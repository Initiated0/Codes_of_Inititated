#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v;
    // functions -> begin(), end(), rbegin(), rend(), cbegin(), cend()

    for(int i = 0; i<10; i++)
        v.push_back(i);

    cout<<"using cout: ";

    for(int i = 0; i<10; i++)
        cout<<v[i]<<" ";

    cout<<endl<<"using printf: ";
    for(int i = 0; i<10; i++)
        printf("%d ", v[i]);


    cout<<endl<<"using pointer: ";
    for(auto itr = v.begin(); itr != v.end(); itr++)
    {
        printf("%d ", *itr);
    }

    cout<<endl<<"using reverse pointer: ";
    for(auto itr = v.rbegin(); itr != v.rend(); itr++)
    {
        printf("%d ", *itr);
    }


    cout<<endl<<"using constant begin pointer: ";
    for(auto itr = v.cbegin(); itr != v.cend(); itr++)
    {
        printf("%d ", *itr);
    }

    cout<<endl<<"using constant reverse begin pointer: ";
    for(auto itr = v.crbegin(); itr != v.crend(); itr++)
    {
        printf("%d ", *itr);
    }

    //without auto

    cout<<endl<<"Size: "<<v.size()<<endl<<"max size: "<<v.max_size()<<endl
    <<"capacity: "<<v.capacity()<<endl;

    vector <int > vec;

    cout<<"cap of vec: "<<vec.capacity()<<endl;

    vec.push_back(1);
    cout<<"cap of vec: "<<vec.capacity()<<endl;

    for(int i = 2; i<= 256; i++)
    {
        vec.push_back(i);
        if(vec.capacity() == i)
        {
            printf("%d\n", vec.capacity());
        }
    }

    //reversing a vector

    for(int i = 0; i< 10/2; i++)
    {
        swap(v[i], v[10-i-1]);
    }

    for(int i = 0; i<10; i++)
        cout<<v[i]<<" ";







    return 0;
}
