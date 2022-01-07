#include <bits/stdc++.h>

using namespace std;

int bigmod(int a, int b, int M)
{
    if (b == 0) return 1 % M;
    int ans = bigmod(a, b/2, M);
    ans = (ans * ans) % M;

    if (b % 2 != 0) ans = (ans * a) % M;

    return ans;

}

int main()
{
    printf("%d\n", bigmod(2, 5, 100));

    return 0;
}
