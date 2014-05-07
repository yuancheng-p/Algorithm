/*
 * May 7, 2014
 * Find out all the primes under a given number
 * Print the number of primes
 */
#include <iostream>
#include <math.h>
using namespace std;

/* Very slow version */
int isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/* Very fast version */
int isPrimeP2(int n)
{
    if (n % 2 == 0)
        return (n == 2);
    if (n % 3 == 0)
        return (n == 3);
    if (n % 5 == 0)
        return (n == 5);

    for (int i = 7; i*i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


int main()
{
    int count = 0;
    int n = 1000;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
            count++;
    }
    cout << count << endl;
}
