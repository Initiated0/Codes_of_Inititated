#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p;
    scanf("%d %d", &n, &p);

    int cnt = 0;
    while(floor(n/p) > 0)
    {
        cnt += n/p;
        p *= p;

    }

    cout<<cnt<<endl;

    return 0;
}
