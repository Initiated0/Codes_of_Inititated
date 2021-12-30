//Sieve Of Eratosthenes

#include <bits/stdc++.h>

using namespace std;

//initializes the arrays as 0
int arr[100+3];
int prime[100];

int sarr[10000+3];
int sprime[2000];
int ssprime[3000+10];

//in segmented sieve you will be given a range and you will have to find all the primes in between that range
void segmented_sieve(int a, int b)
{
    int limit = sqrt(b) + 2;
    printf("Limit : %d\n", limit);
    int idx = 1;
    sarr[0] = sarr[1] = 1;

    sprime[idx++] = 2;

    for (int i = 4; i<=limit; i+= 2)
    {
        sarr[i] = 1;
    }

    for (int i = 3; i<= limit; i += 2)
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


    for (int i = 1; i < idx; i++)
    {
        printf("%d ", sprime[i]);
    }

    printf("\n");


    for (int i = 1; i < idx; i++)
    {
        int primes = sprime[i];

        for (int j = 0; j <= b-a+1; j++)
        {
            if ( (a + j) % primes == 0)
            {
                ssprime[j] = 1;
            }

        }
    }

    for (int i = 0; i<= b - a + 1; i++)
    {
        if (ssprime[i] != 1)
        {
            printf("%d ", (a+i));
        }
    }
}

int main()
{

    for(int i = 0; i<100; i++)
    {
        printf("%d ", prime[i]);
    }
    printf("\n");
    int n = 200;

    arr[0] = arr[1] = 1;
    prime[1] = 2;
    for(int i = 4; i<=100; i+=2) //crossing all even numbers
        arr[i] = 1;

    int primeindex = 2;


    int limit = sqrt(100);
    for(int i = 3; i<n; i += 2) // looping over all odds
    {
        if(arr[i] != 1)
        {
            prime[primeindex++] = i; // the prime number

            for(int j = i * i; j < n; j += 2*i) // here is the actual trick
            {                                   // i == 3; j starts from 9 and increments with 6 (3*2)
                arr[j] = 1;                     // i == 5; j starts from 25 and increments with 10 (5*2)
            }
        }
    }

    printf("Normal Sieve from 1 to N:\n");
    //prime[1] = prime[1] + 1;

    for (int i = 1; i< primeindex; i++)
        printf("%d ", prime[i]);

    printf("\n");

    segmented_sieve(100, 200);

    return 0;
}
