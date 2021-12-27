#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[20];
    int aa[20][20];

    memset(a, 0, sizeof(a));
    memset(aa, 0, sizeof(aa));

    for (int i = 0; i< 20; i++)
    {
        //printf("%d : %d\n", i, a[i]);
        for (int j = 0; j<20; j++)
        {
            printf("(%d,%d)%d ", i,j, aa[i][j]);
        }
        printf("\n");
    }

    char s[] = ".....";

    for (int i = 0; i < 13; i++)
    {
        printf("%c", s[i]);
    }

    char ss[10] = "sadf";

    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", ss[i]);
    }

    printf("\n");

    for (int i = 0; i< 5; i++)
    {
        scanf("%c", &s[i]);
    }

    printf("\n", s);

    for (int i = 0; i< 10; i++) printf("%s", s);


    printf("\n");

    string str = "sadlfj";

    for (int i = 0; i<str.length(); i++)
    {
        printf("%c", str[i]);
    }


    return 0;
}
