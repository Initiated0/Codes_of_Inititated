#include <bits/stdc++.h>

using namespace std;


int egcd(int a, int b, int &x, int &y)
{
    if(a == 0)
    {
        x = 0; y = 1;
        return b;
    }

    int x1, y1;

    int d = egcd(b % a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return d;
}

int main()
{
    /*
        the concept of extended gcd is like this:- gcd of a and b is g;
        now it's possible to find x and y that fulfills the following equation

            a*x + b*y = g // if a = 10 and b = 6 then x = -1 and y = 2

    */
    int x, y;
    printf("gcd: %d\n", egcd(6, 10, x, y));
    printf("x: %d y: %d\n", x, y);



    return 0;
}
