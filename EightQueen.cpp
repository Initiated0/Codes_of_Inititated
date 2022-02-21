#include <bits/stdc++.h>

using namespace std;

int chess[20][20];
int queen[20];
int column[20];
int diagonal1[40];
int diagonal2[40];
int N;

void printboard()
{
    cout<<"Row, Column = ";

    for(int i = 1; i<= N; i++)
        cout<<"("<<i<<","<<queen[i]<<") ";
    cout<<endl;
    return;
}


void NQueen(int aT)
{
    if(aT > N)
    {
        printboard();
        return;
    }

    for(int i = 1; i<= N; i++)
    {
        if(column[i] || diagonal1[i+aT] || diagonal2[N+i-aT]) continue;

        queen[aT] = i;
        chess[aT][i] = i;
        column[i] = diagonal1[i+aT] = diagonal2[N+i-aT] = 1;
        NQueen(aT+1);
        column[i] = diagonal1[i+aT] = diagonal2[N+i-aT] = 0;
    }
}


int main()
{
    scanf("%d", &N);

    NQueen(1);
    return 0;
}
