#include <bits/stdc++.h>

using namespace std;


int binaryarray[66];


void DecimalToBinary(int n)
{
    int idx = 0;

    while(n>0)
    {
        binaryarray[idx++] = n % 2;
        n /= 2;
    }

    for(int i = 0, j = idx-1; i<(idx/2); i++, j--)
    {
        swap(binaryarray[i], binaryarray[j]);

    }

    for(int i = 0; i<idx; i++)
    {
        printf("%d", binaryarray[i]);
    }
    printf("\n");
}


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        cin>>n;

        DecimalToBinary(n);
    }

    return 0;
}
