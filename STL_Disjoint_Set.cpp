#include <bits/stdc++.h>

using namespace std;



int Find(int x, int p[])
{
    if(p[x] == x) return x;
    return p[x] = Find(x, p);
}

void Union(int nowownes, int owner, int p[])
{
    p[Find(nowownes, p)] = Find(owner, p);
}

int main()
{
    int p[100];

    for(int i = 0; i<100; i++)
        p[i] = i;

    cout<<Find(1, p)<<endl;

    for(int i = 0; i<20; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x] = y;
    }

    cout<<Find(7, p)<<endl;





}
