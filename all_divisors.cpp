#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> divisors[1000];

    int n = 500;

    for (int i = 1; i<=n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);

        }

    }
    int mxdivnum, mxdiv = 0;


    for (int i = 1; i<= n; i++)
    {
        printf("%d :-", i);
        for (int j = 0; j< divisors[i].size(); j++)
        {
            printf("%d ", divisors[i][j]);
        }
        printf("::::: %d\n", divisors[i].size());

    }

    return 0;
}
