#include<iostream>
#include <math.h>

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}

void foo(double input)
{
    double integral = floor(input);
    double frac = input - integral;

    const long precision = 1000000000; // This is the accuracy.

    long gcd_ = gcd(round(frac * precision), precision);

    long denominator = precision / gcd_;
    long numerator = round(frac * precision) / gcd_;

    std::cout << integral << " + ";
    std::cout << numerator << " / " << denominator << std::endl;
}

using namespace std;
int main() {
    float a, b, c, d, X;
    cout<<"The form of the linear equation in one variable is: aX + b = cX + d"<<endl;
    cout<<"Enter the values of a, b, c, d : "<<endl;
    cin>>a>>b>>c>>d;
    cout<<"The equation is "<<a<<"X + "<<b<<" = "<<c<<"X + "<<d<<endl;

    if(a==c && b==d)
        cout<<"There are infinite solutions possible for this equation"<<endl;
    else if(a==c)
        cout<<"This is a wrong equation"<<endl;
    else {
        X = (d-b)/(a-c);
        foo(X);
    }
}