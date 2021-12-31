//Sieve Of Eratosthenes

#include <bits/stdc++.h>

using namespace std;

//initializes the arrays as 0
int arr[1000+3];
int prime[1000];

int sarr[10000+3];
int sprime[2000];
int ssprime[3000+10];

//in segmented sieve you will be given a range and you will have to find all the primes in between that range
void segmented_sieve(int a, int b)
{
    int limit = sqrt(b) + 2;
    //printf("Limit : %d\n", limit);
    int idx = 1;
    sarr[0] = sarr[1] = 1;

    sprime[idx++] = 2;

    for (int i = 4; i<=limit; i+= 2)
    {
        sarr[i] = 1;
    }

    for (int i = 3; i <= limit; i += 2)
    {
        if (sarr[i] != 1)
        {
            sprime[idx++] = i;

            for (int j = i * i; j <= limit; j += i * 2)
            {
                sarr[j] = 1;
            }

        }
    }

    printf("Segmented Sieve:\n");


    //for (int i = 1; i < idx; i++)
    //{
        //printf("%d ", sprime[i]);
    //}

    //printf("\n");


    for (int i = 1; i < idx; i++)
    {
        int primes = sprime[i];

        for (int j = a; j <= b-a+1; j++)
        {
            if ( ((a + j) % primes == 0) && (a+j) != primes)
            {
                ssprime[j] = 1;
            }

        }
    }

    for (int i = a; i<= b - a + 1; i++)
    {
        if (ssprime[i] != 1)
        {
            printf("%d ", (a+i));
        }
    }
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
