#include <bits/stdc++.h>

using namespace std;

int num[8+3];
int sum[8*4+3];


int SegmentTreeQuery(int AT, int L, int R, int l, int r)
{
    if(r < L || l > R) return 0; // either the range is l...r...L....R or L...R...l...r
    if(l <= L && r >= R) return sum[AT]; // l...L...R...r

    // L...l...r...R

    int mid = (L + R) / 2;

    int x = SegmentTreeQuery(AT*2, L, mid, l, r);
    int y = SegmentTreeQuery(AT* 2 + 1, mid+ 1, R, l, r);

    return x+y;

}

void SegmentTreeUpdate(int AT, int L, int R, int pos, int u)
{
    if(L == R)
    {
        sum[AT] += u;
        return;
    }

    int mid = (L+R) / 2;

    if (mid >= pos) SegmentTreeUpdate(AT * 2, L, mid, pos, u);
    else SegmentTreeUpdate(AT * 2 + 1, mid + 1, R, pos, u);

    sum[AT] = sum[AT*2] + sum[AT*2 + 1];

    return;

}


void SegmentTreeBuild(int AT, int L, int R)
{
    sum[AT] = 0;

    if(L == R)
    {
        sum[AT] = num[L];
        return;
    }

    int mid = (L+R)/2;

    SegmentTreeBuild(AT*2, L, mid);
    SegmentTreeBuild(AT*2+1, mid+1, R);

    sum[AT] = sum[AT*2] + sum[AT*2+1];

    return;
}

int main()
{
    freopen("ST.txt", "r", stdin);
    for(int i = 1; i<= 8; i++)
        scanf("%d", &num[i]);

    SegmentTreeBuild(1, 1, 8); // first one is at, second one is leftmost in the range,
                               // and third is rightmost in the range
    for(int i = 1; i<= 8; i++)
        cout<<num[i]<<" ";
    cout<<endl;

    for(int i = 1; i<= 20; i++)
        cout<<sum[i]<<" ";
    cout<<endl;

    SegmentTreeUpdate(1, 1, 8, 3, 10);


    for(int i = 1; i<= 20; i++)
        cout<<sum[i]<<" ";
    cout<<endl;

    cout<<SegmentTreeQuery(1, 1, 8, 5, 8)<<endl;


    return 0;
}
