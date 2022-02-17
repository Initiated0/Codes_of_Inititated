#include <bits/stdc++.h>

using namespace std;

int num[20+3], mark[20+3];
int N = 5;


//all possible permutations of numbers from 1 to N

void permutation(int aT)
{
    // base case
    if(aT == N+1)
    {
        for(int i = 1; i<= N; i++)
        {
            printf("%d ", num[i]);

        }
        cout<<endl;
        return;
    }

    for(int i = 1; i<= N; i++)
    {
        if(!mark[i])
        {
            num[aT] = i;
            mark[i] = 1;
            permutation(aT+1);
            mark[i] = 0;
        }
    }

}

int main()
{
    permutation(1);

    return 0;
}
