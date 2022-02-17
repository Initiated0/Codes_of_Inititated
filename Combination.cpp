#include <bits/stdc++.h>

using namespace std;

int num[20+3];
int n, k;

void combination1(int aT, int left)
{
    if(left > n - aT + 1) return;

    if(aT == n + 1)
    {
        for (int i = 1; i <= k; i++)
        {
            printf("%d ", num[i]);
        }
        cout<<endl;
        return;
    }

    if(left)
    {
        num[k-left + 1] = aT;
        combination1 (aT+1, left-1);
    }
    combination1(aT+1, left);

}

void combination2(int aT, int last)
{
    if (aT == k+1)
    {
        for (int i = 1; i<= k; i++)
        {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }

    for(int i = last + 1; i <= n - k + aT; i++)
    {
        num[aT] = i;
        combination2(aT + 1, i);
    }
}

int main()
{
    n = 8;
    k = 4;

    combination1(1, 4);
    cout<<"DONE"<<endl<<endl;
    combination2(1, 0);


    return 0;
}
