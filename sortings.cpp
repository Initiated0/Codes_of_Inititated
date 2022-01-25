#include <bits/stdc++.h>

using namespace std;

int N = 13;
int unsortedarray[13+3];
int mx;

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

    return a;
}

void selectionSort(int a[])
{
    for(int i = 0; i<N; i++)
    {
        for(int j = i+1; j<N; j++)
        {
            if(a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void bubbleSort(int num[])
{
    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j <N - 1; j++)
        {
            if(num[j+1] < num[j])
            {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
                //swap(num[j], num[j+1]);
            }
        }
    }
}

void mergeSort(int hi, int lo)
{
    int temp[13+3];
    memset(temp, 0, sizeof(temp));

    if(lo == hi) return;

    int mid = (lo + hi) / 2;

    mergeSort(lo, mid);
    mergeSort(mid+1, hi);

    int i, j, k;

    for(int i = lo, j = mid+1, k = lo; k <= hi; k++)
    {
        if(i == mid + 1) temp[k] = unsortedarray[j++];
        else if(j == hi + 1) temp[k] = unsortedarray[i++];
        else if(unsortedarray[i] < unsortedarray[j]) temp[k] = unsortedarray[i++];
        else temp[k] = unsortedarray[j++];
    }
    for(k = lo; k<= hi; k++)
        unsortedarray[k] = temp[k];

    return;
}

void countingSort(int num [], int maxnum)
{
    int temp[maxnum+3];
    memset(temp, 0, sizeof(temp));

    for(int i = 0; i<N; i++)
    {
        temp[num[i]]++;
    }

    for(int i = 0, j = 0; i <= maxnum; i++)
    {
        if(temp[i] != 0)
        {
            while(temp[i]--)
            {
                unsortedarray[j++] = i;
            }
        }


    }
}

void generateUnSortedArray(int k)
{

    srand(k);
    mx = 0;
    memset(unsortedarray, 0, sizeof(unsortedarray));
    for(int i = 0; i<N; i++)
    {
        unsortedarray[i] = rand();
        if (mx < unsortedarray[i])
            mx = unsortedarray[i];
    }
    cout<< "Unsorted array             : ";
    for(int i = 0; i<N; i++)
    {
        printf("%d ", unsortedarray[i]);
    }
    cout<<endl;

}

int main()
{
    /*Insertion Sort*/
    generateUnSortedArray(1);
    int * aray = insertionSort(unsortedarray);
    cout<<"Insertion  Sort TC-> O(n^2): ";
    for(int i = 0; i<N; i++)
    {
        printf("%d ", *(aray+i));
    }
    cout<<endl;
    cout<<endl;

    /*Selection Sort*/
    generateUnSortedArray(2);
    cout<<"Selection  Sort TC-> O(n^2): ";
    selectionSort(unsortedarray);
    for(int i = 0; i<N; i++)
    {
        printf("%d ", unsortedarray[i]);
    }
    cout<<endl;
    cout<<endl;

    /*Bubble Sort*/
    generateUnSortedArray(3);
    bubbleSort(unsortedarray);
    cout<<"Bubble    Sort  TC-> O(n^2): ";
    for(int i = 0; i<N; i++)
    {
        printf("%d ", unsortedarray[i]);
    }
    cout<<endl;
    cout<<endl;

    /*Merge Sort*/
    generateUnSortedArray(4);
    mergeSort(0,12);
    cout<<"Merge Sort TC-> O(n*log(n)): ";
    for(int i = 0; i<N; i++)
    {
        printf("%d ", unsortedarray[i]);
    }
    cout<<endl;
    cout<<endl;

    /*Counting Sort*/
    generateUnSortedArray(5);
    //In counting sort there can be no negative number
    // and you will also need the largest number in the array
    countingSort(unsortedarray, mx);
    cout<<"Counting   Sort TC-> O(N+n): ";
    for(int i = 0; i<N; i++)
    {
        printf("%d ", unsortedarray[i]);
    }
    cout<<"mxnumber :"<<mx<<endl;
    cout<<endl;








    return 0;
}
