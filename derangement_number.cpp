#include <bits/stdc++.h>

using namespace std;

int derangement(int n)
{
    if(n <= 0) return 1;
    else if (n == 1) return 0;
    else return (((n-1) * derangement(n-2)) + ((n-1) * derangement(n-1)));
}


int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", derangement(n));
    return 0;
}
