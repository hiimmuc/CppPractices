#include<iostream>
using namespace std;

int main()
{
    //for initialize variables
    int numerator1, denominator1, numerator2, denominator2, x, y, c, gcd_no;
    
    //To take user input of numerators and denominators
    cin >> numerator1 >> denominator1;
    cin >> numerator2 >> denominator2;
    //numerator
    x=(numerator1*denominator2)+(denominator1*numerator2); 
    
    //denominator
    y=denominator1*denominator2; 
    
	// Trick part. Reduce it to the simplest form by using gcd.
    for(c=1; c <= x && c <= y; ++c)
    {
       if(x%c==0 && y%c==0)
          gcd_no = c;
    }
    
    //To display fraction of givien numerators and denominators
    cout << x/gcd_no << " " << y/gcd_no << endl;
    return 0;
}