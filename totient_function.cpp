#include <bits/stdc++.h>

//Two numbers are Co Prime when they only have 1 as common divisor and nothing else.

// a list of Co primes -> {1, 3, 5, 12, 14}

using namespace std;

int phi[1000006], mark[1000006];

void sievephi(int n)
{

    for (int i=1; i<=n; i++) phi[i] = i;

    phi[1] = mark[1] = 1;

    for (int i=1; i<=n; i++)
    {
        if(!mark[i])
        {
            for(int j=i; j<=n; j+=i)
            {
                mark[j] = 1;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
}

int main()
{
    int n = 100;
    sievephi(n);

    for(int i = 1; i<n; i++)
    {
        printf("%d -> %d\n", i, phi[i]);
    }

    printf("\n");

    return 0;
}
