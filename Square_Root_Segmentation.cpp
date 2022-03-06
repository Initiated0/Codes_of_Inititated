#include <bits/stdc++.h>

using namespace std;


int manualSRS(int i, int j, int amount[])
{
    int ans = 0;
    for(int ii = i; ii<= j; ii++)
    {
        ans += amount[ii];
    }
    return ans;
}

int main()
{
    freopen("SRS.txt", "r", stdin);

    int amount [10000+3];
    int sum[100+3];
    int k = 4;
    int x, y;

    memset(amount, 0, sizeof(amount));
    memset(sum, 0, sizeof(sum));

    // Square Root Segmentation formulas
    /*
        summation of 1st k elements in [0], second k elements in [1], third elements in [2]
        how do you calculate where the sum is?
        using i/k; if k = 4; and i = 6 => i/k = 6/4 = 1 [integer division] [0] = [0,1,2,3],
        [1] = [4,5,6,7]
        now you need to check if i and j are in the same block. if they are, loop over them
        else
                head of a series is k*p and tail of a series is k * (p+1) - 1
                p is actually the integer division of i/k
    */

    //updating amount and segmented total array
    int N;
    scanf("%d", &N);
    for(int i = 0; i< N; i++)
    {

        scanf("%d %d", &x,&y);
        amount[x] += y;
        //cout<<amount[x]<<endl;
        sum[x/k] += y;
    }

    int T;
    scanf("%d", &T);

    while(T--)
    {
        int i, j;
        scanf("%d %d", &i, &j);

        // from i to j calculate the sum

        int ans1 = manualSRS(i, j, amount);
        cout<<"Manual SRS   :  "<<ans1<<endl;

        x = i / k; // i belongs to the x segment
        y = j / k; // j belongs to the x segment
        int ans = 0;

        if(x == y)
        {
            for(int ij = i; ij <= j; ij++)
            {
                ans += amount[ij];
            }
        }
        else
        {
            int tail, head;

            tail = k*(x+1) - 1; // to find the last element of x segment

            head = k * y;       // to find the first element of y segment

            for(int ii = i; ii<= tail; ii++)
            {
                ans += amount[ii];
            }

            for(int ii = head; ii<= j; ii++)
            {
                ans += amount[ii];
            }

            for(int ii = x+1; ii<= y-1; ii++)
            {
                ans += sum[ii];
            }
        }

        cout<<"SquareRootSeg : "<<ans<<endl<<endl;

    }




    return 0;
}
