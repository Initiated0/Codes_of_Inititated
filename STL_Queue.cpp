#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue <int > q;
    for(int i = 0; i<10; i++)
    {
        q.push(rand());
    }

    cout<<"Size: "<<q.size()<<endl;

    cout<<q.front()<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
