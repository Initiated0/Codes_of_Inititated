#include <bits/stdc++.h>

using namespace std;

int maxres(int a, int b) {return (a > b) ? a : b; }

int knapsack(int W, int N, int w[], int v[])
{
    if(W == 0 || N == 0)
        return 0;

    if(w[N-1] > W)
        return knapsack(W, N-1, w, v);
    else {
        return maxres(v[N-1] + knapsack(W-w[N-1], N-1, w, v), knapsack(W, N-1, w, v));
    }
}

int knapsackTopDown(int W, int N, int w[], int v[])
{
    int  mem[N+1][W+1];
    //memset(mem, 0, sizeof(mem));

    for(int i = 0; i<= N; i++)
    {
        for(int j = 0; j<=W; j++)
        {
            if(i == 0 || j == 0)
            {
                mem[i][j] = 0;
            }
            else if (w[i-1] <= j)
            {
                mem[i][j] = maxres(v[i-1] + mem[i-1][j-w[i-1]], mem[i-1][j]);
            }
            else
            {
                mem[i][j] = mem[i-1][j];
            }
        }
    }

    return mem[N][W];


}


int knapSack2(int W, int n, int wt[], int val[])
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}


int main()
{
    int w[] = {2, 4, 6, 8, 10};
    int v[] = {1, 5, 5, 4, 10};
    int W = 16;
    int N = sizeof(w) / sizeof(w[0]); // a cool way to figure out the number of array elements
    //cout<<sizeof(w)<<" / "<<sizeof(w[0])<<" : "<<N<<endl;

    cout<<knapsack(W, N, w, v)<<endl;


    cout<<knapsackTopDown(W, N, w, v)<<endl;

    cout<<knapSack2(W, N, w, v)<<endl;



    return 0;
}
