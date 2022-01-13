#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b)
{
    if (b == 0) return a;
    else if(a % b == 0) return b;
    else return gcd(b, a%b);
}
int NCR(int n, int r)
{
    int combi[n+3];
    int cancel[r+3];

    memset(combi, 0, sizeof(combi));


    int idx = 0;
    for(int i = n; i > n-r; i--)
    {
        combi[idx++] = i;
    }

    for(int i = 2; i<=r; i++)
    {
        cancel[i] = i;
    }

    for(int i = 2; i<=r; i++)
    {
        for(int j = 0; j<idx; j++)
        {
            if((combi[j] % cancel[i] == 0) && cancel[i] != 1)
            {
                combi[j] /= cancel[i];
                cancel[i] /= cancel[i];
            }
            else if(cancel[i] != 1)
            {
                int gcdnum = gcd(combi[j] , cancel[i]);

                if(gcdnum != 1)
                {
                    combi[j] /= gcdnum;
                    cancel[i] /= gcdnum;
                }
            }
        }
    }

    int ans = 1;
    for(int i = 0; i<idx; i++)
    {
        ans *= combi[i];
    }

    return ans;

}

/*
catalan number formula:-

    Cn = (1/(n+1)) * (2*n)Cn
    or,
    Cn = (2*n)Cn - (2*n)C(n+1)
*/

int catalan_num1(int n)
{
    double x = NCR(2*n, n)/(n+1) ;
    return x;
}

int catalan_num2(int n)
{
    return (NCR(2*n, n) - NCR(2*n, n+1));
}

int main()
{
    int n = 1;

    while(n != 0)
    {
        scanf("%d", &n);


        printf("Method 1: %d\n", catalan_num1(n));

        printf("Method 2: %d\n", catalan_num2(n));

    }
    return 0;
}
