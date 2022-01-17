#include <bits/stdc++.h>

using namespace std;

int N = 20;
/*
    The array send through a function sends the address of the first element
    so any changes in the functions array will also change the original one
    no need to return anything
    here just the process of returning array is shown through pointer

    the declaration of the function will tell that it is returning a pointer
    will return the array without any braces

    the return should be saved in a pointer to an int
    that will the address of the first element
    iterating one integer to get the next element and using pointer notation to express the value of the array element

*/

int *insertionSort(int a[])
{
    /*for(int i = 0; i<N; i++)
        cout<<a[i]<<" ";
    cout<<endl; */

    for (int i = 0; i<N; i++)
    {
        int x = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > x)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }

    for(int i = 0; i<N; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return a;
}

int main()
{
    int aray[] = {2, 3, 10, 9, 6, 4, 5, 7, 6, 5, 4, 2, 3, 1, 5, 3, 9, 9, 9, 1};

    int *a = insertionSort(aray);

    for(int i = 0; i<N; i++)
        cout<<*(a+i)<<" ";

    cout<<endl;

    for(int i = 0; i<N; i++)
        cout<<aray[i]<<" ";
    return 0;
}
