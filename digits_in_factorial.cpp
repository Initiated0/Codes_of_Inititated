#include <bits/stdc++.h>

using namespace std;


    // if you take the log (Base 10) of factorial of the number you will get a good approximation
    // floor the result and add 1

double digitsinfactorial(int num)
{
    double ans = 0.0;
    for (int i = 1; i <= num; i++)
    {
        ans += log10(i);
    }
    ans = (floor(ans) + 1);


    return ans;
}

int main()
{
    printf("%lf\n", digitsinfactorial(50));
    return 0;
}
