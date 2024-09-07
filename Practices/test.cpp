#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int sum(int a, int b, int &carry)
{
    int result = a+b+carry;
    if (result >= 10) {
        result -= 10;
        carry = 1;
    } else {
        carry = 0;
    }
    return result;
}

string add(string a, string b)
{
    int s {0}, carry {0};

    if (b.length() > a.length() ||
        (b.length() == a.length() && b[0] - '0' > a[0] - '0')) {
        swap(a, b);
    }
    string c = "";
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0) {
        if (j < 0) {
            s = sum(a[i] - '0', 0, carry);
            // c += sum(a[i] - '0', m, 1);
            i--;
        } else {
            s = sum(a[i] - '0', b[j] - '0', carry);
            i--;
            j--;
        }
        c += s+'0';
    }
    if (carry)
        c += '1';
    for (int i = 0; i <= (c.length() - 1) / 2; i++)
        swap(c[i], c[c.length() - 1 - i]);
    return c;
}

int main(){
    string a, b;
    ifstream inp("INP/test.TXT");
    ofstream out("OUT/test.TXT");
    inp >> a >> b;
    out << add(a, b);
    inp.close();
    out.close();
    return 0;
}