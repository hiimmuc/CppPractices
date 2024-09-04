import math
import cv2
import numpy as np

A = 64


# Read the image
image = cv2.imread(
    './Flag_of_Vietnam.png')

image = cv2.resize(image, (int(A/0.4) - 1, int(math.ceil(2 * A/3))))
# Convert the image to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
print(gray_image.shape)
# Save the grayscale image matrix to a text file
np.savetxt('./Flag_of_Vietnam.txt', gray_image, fmt='%d')

# Save the grayscale image to a new image file
# read file from the previous output, if the value is 90 convert to # and * for else
lines = []
new_lines = []

max_width = 0

with open("./Flag_of_Vietnam.txt") as f:
    lines = f.readlines()
    for line in lines:
        list_char = line.strip().split(" ")
        new_lines.append("")
        width = 0
        for char in list_char:
            if str(char) == "90":
                char = "#"
            else:
                char = "*"
                width += 1
            new_lines[-1] += char
            max_width = max(max_width, width)

        new_lines[-1] += "\n"

print(max_width)


def calculate_radius(max_width):
    R1 = max_width / (2 * (math.sin(36 * math.pi/180)/math.cos(72 * math.pi/180) +
                           math.sin(36 * math.pi/180)))

    R2 = max_width * (math.tan(36 * math.pi/180) +
                      math.tan(54 * math.pi/180)) / (2 * (1/math.cos(36 * math.pi/180) + 1))
    print(R1, R2)


calculate_radius(max_width)

with open("./Flag_of_Vietnam_cvt.txt", "w") as f:
    f.writelines(new_lines)
