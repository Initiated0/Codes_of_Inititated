#include <bits/stdc++.h>

using namespace std;

int combarr[100];
int grid[100][100];
/*
nCr = taking r items from n items; since it is a combination problem, there is no ordering involved.
A shortcut is in the formula

nCr = n! / ((n-r)! * r!)

you can take only r numbers from n! (starting from the end of n!) because (n-r)! cancels out the rest.

10C6 = 10! / ((10-6)! * 6!)
     = 10! / (4! * 6!)
     = (10*9*8*7*6*5) / 6!
*/

int GCD(int a, int b)
{
    if (b == 0) return a;
    else if (a % b == 0) return b;
    return GCD (b, a % b);
}

int NCR (int n, int r)
{
    if(n == r) return n;
    int idx = 0;

    int cancelarr[r+3];

    memset(cancelarr, 0, sizeof(cancelarr));

    for(int i = n; i > (n-r); i--)
    {
        combarr[idx++] = i;

    }

    for (int i = 1; i <= r; i++)
    {
        cancelarr[i] = i;
    }


    for(int i = 2; i<=r; i++)
    {
        if(cancelarr[i] != 1)
        {
            for(int j = 0; j<idx; j++)
            {
                if(combarr[j] != 1 && (combarr[j] % cancelarr[i] == 0))
                {
                    combarr[j] /= cancelarr[i];
                    cancelarr[i] = 1;
                }
                else if (combarr[j] != 1)
                {
                    int gcd = GCD(combarr[j], cancelarr[i]);

                    if(gcd != 1)
                    {
                        combarr[j] /= gcd;
                        cancelarr[i] /= gcd;
                    }
                }
            }
        }

    }
    int ans = 1;

    for(int i = 0; i<idx; i++)
    {
        ans *= combarr[i];

    }

    return ans;

}

void NCR_O_n(int a, int b)
{
    grid[0][0] = 1;

    for (int i = 1; i<10; i++)
    {
        for (int j = 0; j<10; j++)
        {
            if(j>i) grid[i][j] = 0;
            else if(j == i || j == 0) grid[i][j] = 1;
            else grid[i][j] = grid[i-1][j-1] + grid[i-1][j];
        }
    }
}

int main()
{
    int a, b;
    int x=3;

    while(x--)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", NCR(a, b));

        NCR_O_n(a, b);

        for(int i = 0; i<10; i++)
        {
            for(int j = 0; j<10; j++)
            {
                printf("%d ", grid[i][j]);
            }
            cout<<endl;
        }
    }

    return 0;
}
