//Sieve Of Eratosthenes

#include <bits/stdc++.h>

using namespace std;

//initializes the arrays as 0
int arr[1000+3];
int prime[1000];

int sarr[2000+3];
int sprime[2000];
int ssprime[2000+3];

//in segmented sieve you will be given a range and you will have to find all the primes in between that range
void segmented_sieve(int a, int b)
{
    // range is from a to b
    // what i have to do
    // use sieve until b^(1/2)
    // get the primes
    // then use those primes to cross out numbers between the range
    // collect the remainders
    int limit = sqrt(b);
    sarr[0] = sarr[1] = 1;

    int idx = 1;
    sprime[idx++] = 2;

    for (int i = 4; i<= limit; i+=2)
    {
        sarr[i] = 1;
    }

    for (int i = 3; i <= limit; i+=2)
    {
        if(sarr[i] != 1)
        {
            sprime[idx++] = i;
            for(int j = i * i; j <= limit; j+= i *2)
            {
                sarr[j] = 1;
            }
        }
    }

    printf("Segemented Sieve:\n");
    int idx2 = 0;
    for (int j = a; j <= b; j++)
    {
        int flag = 1;
        for (int i = 1; i<idx; i++)
        {
            if(j % sprime[i] == 0 && j != sprime[i])
            {
                flag = 0;
            }
        }
        if(flag != 0)
        {
            ssprime[idx2++] = j;
        }
    }

    for(int i = 0; i<idx2; i++)
    {
        printf("%d ", ssprime[i]);
    }

    printf("\n");



}

int main()
{
    //sieve of 1 to N
    int N = 1000;

    arr[0] = arr[1] = 1;

    int idx = 1;
    prime[idx++] = 2;

    for (int i = 4; i<= N; i+=2)
    {
        arr[i] = 1;
    }

    for (int i = 3; i <= N; i+=2)
    {
        if(arr[i] != 1)
        {
            prime[idx++] = i;
            for(int j = i * i; j <= N; j+= i *2)
            {
                arr[j] = 1;
            }
        }
    }
    cout<<"Normal Sieve from 1 to N"<<endl;

    for(int i = 1; i<47; i++)
    {
        printf("%d ", prime[i]);
    }

    cout<<endl;

    segmented_sieve(100, 200);



    return 0;
}
