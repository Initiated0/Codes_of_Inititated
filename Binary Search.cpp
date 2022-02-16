#include <bits/stdc++.h>

using namespace std;


int binarySearch(int arr[], int lo, int hi, int num)
{
    while(hi - lo > 5)
    {
        int mid = (lo + hi) / 2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(num < arr[mid])
        {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }

    for (int i = lo; i<= hi; i++)
    {
        if(arr[i] == num)
            return i;
    }

    return -1;


}

int main()
{
    int arr[100+3];

    for(int i = 0; i<100; i++)
        arr[i] = rand();

    sort(arr, arr+100);


    for(int i = 0; i<100; i++)
        cout<< arr[i]<<" ";

    cout<<endl;
    int lo = 0, hi = 99, x = 520;

    while(x != -1)
    {
        scanf("%d", &x);
        int res = binarySearch(arr, lo, hi, x);

        if(res == -1) cout<<"The number is not in the array."<<endl;
        else cout<<"position of "<<x <<" : "<<res + 1<<endl;

    }
    return 0;
}
