//Sieve Of Eratosthenes

#include <bits/stdc++.h>

using namespace std;

//initializes the arrays as 0
int arr[100+3];
int prime[100];

int main()
{
    int n = 100;

    arr[0] = arr[1] = 1;
    for(int i = 4; i<=100; i+=2) //crossing all even numbers
        arr[i] = 1;

    int primeindex = 1;
    prime[primeindex++] = 2;

    int limit = sqrt(100);
    for(int i = 3; i<n; i += 2) // looping over all odds
    {
        if(arr[i] == 0)
        {
            prime[primeindex++] = i; // the prime number

            for(int j = i * i; j < n; j += 2*i) // here is the actual trick
            {                                   // i == 3; j starts from 9 and increments with 6 (3*2)
                arr[j] = 1;                     // i == 5; j starts from 25 and increments with 10 (5*2)
            }
        }
    }

    for (int i = 1; i< primeindex; i++)
        printf("%d ", prime[i]);

    return 0;
}
