# VOVA game

## Đề bài

- Cho hai dãy số nguyên dương $a$, $b$ với độ dài lần lượt là $n$, $m$ ($n, m > 1$). Chia mỗi dãy thành $k$ nhóm.
- Hãy chọn $k$ và các cặp số nguyên dương $(x_{1}, y_{1}), (x_{2}, y_{2})..., (x_{k + 1}, y_{k + 1})$. Nhóm $i$ dãy A gồm những phần tử nằm giữa $x_{i}$ và $x_{i+1}$, và nhóm $i$ dãy B gồm những phần tử nằm giữa $y_{i}$ và $y_{i+1}$, $x$ và $y$ là các chỉ số. Ta có các điều kiện:

    - $(x_{1}, y_{1}) = (1, 1)$ và $(x_{k + 1}, y_{k + 1}) = (n + 1, m + 1)$ 

    - Với mọi $i \geq 2$, $x_{i - 1} < x_{i}$ và $y_{i - 1} < y_{i}$ 

    - Tối thiểu hóa hàm chi phí $c = \Sigma_{i = 1}^{k}c_{i}$ với $c_{i} = (s_{i} - u_{i}) \cdot (t_{i} - v_{i})$

        > $s_{i} = \Sigma_{j = x_{i}}^{x_{i + 1} - 1}a[j]$

        > $u_{i} = x_{i + 1} - x_{i}$

        > $t_{i} = \Sigma_{j = y_{i}}^{y_{i + 1} - 1}b[j]$

        > $v_{i} = y_{i + 1} - y_{i}$

## Nhận xét

- Với mọi $i$ ($1 \leq i \leq k$), 
  
    - $s_{i} - u_{i} = \Sigma_{j = x_{i}}^{x_{i + 1} - 1}a[j] - (x_{i + 1} - x_{i}) = \Sigma_{j = x_{i}}^{x_{i + 1} - 1}(a[j] - 1)$

    - $t_{i} - v_{i} = \Sigma_{j = y_{i}}^{y_{i + 1} - 1}b[j] - (y_{i + 1} - y_{i}) = \Sigma_{j = y_{i}}^{y_{i + 1} - 1}(b[j] - 1)$

    $\Rightarrow c_{i} = (\Sigma_{j = x_{i}}^{x_{i + 1} - 1}(a[j] - 1)) \cdot (\Sigma_{j = y_{i}}^{y_{i + 1} - 1}(b[j] - 1))$
    
- Giả sử có một vị trí $i$ ($1 \leq i \leq k$) mà dãy con $a$ và $b$ tương ứng đều có độ dài lớn hơn một ($x_{i + 1} - x_{i} \geq 2$ và $y_{i + 1} - y_{i} \geq 2$). Đặt 

    - $A = a[x_{i}] - 1$
    - $B = b[y_{i}] - 1$
    - $C = \Sigma_{j = x_{i} + 1}^{x_{i + 1} - 1}(a[j] - 1)$
    - $D = \Sigma_{j = y_{i} + 1}^{y_{i + 1} - 1}(b[j] - 1)$
    
    $\Rightarrow c_{i} = (A + C)(B + D) = AB + AD + BC + CD$
    Vì $A, B, C, D \geq 0$, $c_{i} \geq AB + CD$ (Bất đẳng thức Cauchy-Schwarz)
    
    $\Rightarrow$ Với một cặp dãy con của $a$ và $b$ bất kì với độ dài đều lớn hơn một, ta luôn có thể tách thành hai cặp dãy con nhỏ hơn với một cặp có độ dãy đều bằng một và cặp còn lại gồm các phần tử còn lại mà không làm tăng $c$. Nếu ta thực hiện thao tác trên cho đến khác không thể thực hiện được nữa thì với mọi cặp dãy con, một trong hai dãy phải có độ dài bằng một.
    
   
## Ý tưởng

- Ta có thể dùng quy hoạch động với hàm $F(x, y)$ có chi phí nhỏ nhất của của $a[x...n]$ và $b[y...m]$. Kết quả bài toán là $F(n, m)$.
- Với nhận xét đã nếu trên, ta có thể tính $F(x, y)$ bằng công thức:
  
  $F(x, y)$ = $min(F(x - 1, y), F(x - 1, y - 1), F(x, y - 1))$ + $(a[x] - 1)$ $\cdot (b[y] - 1)$



## Thuật toán
Tạo mảng $dp$ kích thước $m$, $n$



    
## Độ phức tạp

- Có $m \cdot n$ trạng thái và độ phức tạp để chuyển trạng thái là $O(1)$. Vì vậy, độ phức tạp thời gian của thuật toán là $O(m \cdot n)$

## Cài đặt
 
- Trong quá trình cài đặt, để tránh việc sử dụng mảng hai chiều cho hàm quy hoạch động làm bộ nhớ sử dụng vượt mức cho phép, ta có thể tính các trạng thái theo từng lớp theo $y$ do cái trạng thái $(x, y)$ chỉ cần cái trạng thái ở $y$ và $y + 1$ để tính toán.
