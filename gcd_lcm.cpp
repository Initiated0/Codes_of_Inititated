#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a; // between a,0; a is the gcd
    else if(a % b == 0) return b; // when b divides a, b is the gcd
    else return gcd(b, a%b); // a = b.k + c //if a number is to divide both a and b then it will also divide c // find the gcd of b and a%b
}

int lcm(int a, int b)
{

    int lcm = (a / gcd(a,b)) * b;
    return lcm;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = gcd(a, b);
    int ans2 = lcm(a, b);

    printf("GCD: %d\nLCM: %d\n", ans, ans2);
    return 0;
}
