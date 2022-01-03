#include <bits/stdc++.h>

//list of all divisors of N
//number of divisors (NOD) and sum of divisors(SOD)

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
        int sum = 0;
        printf("%d :-", i);
        for (int j = 0; j< divisors[i].size(); j++)
        {
            printf("%d ", divisors[i][j]);
            sum += divisors[i][j];
        }
        printf("::::: NOD: %d  SOD: %d\n", divisors[i].size(), sum);

    }

    return 0;
}
