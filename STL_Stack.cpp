#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack <int> stk;

    while(!stk.empty())
    {
        stk.pop();
    }

    for(int i = 0; i<10; i++)
    {
        stk.push(rand());
    }

    cout<<"top: "<<stk.top()<<endl;
    cout<<"size: "<<stk.size()<<endl;
    cout<<"empty?: "<<stk.empty()<<endl;

    while(!stk.empty())
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;

    stack <string> stkstr;
    string str;

    for(int i = 0; i<10; i++)
    {
        cin>>str;
        stkstr.push(str);
    }
    while(!stkstr.empty())
    {
        cout<<stkstr.top()<<endl;
        stkstr.pop();
    }
    return 0;
}
