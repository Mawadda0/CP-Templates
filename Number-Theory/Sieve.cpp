#include <Template.h>


vector <bool> sieves(1000001, 1); // Sieve (Primes From 1 to n)
void sieve(ll n = 1000001)
{
    sieves[0] = sieves[1] = 0;
    for(ll i = 2; i * i <= n; i++)
    {
        if(sieves[i])
        {
            for(ll j = i * i; j <= n; j += i) sieves[j] = 0;
        }
    }
}

vector <bool> lin_sieve(1e6, 1); // Linear Sieve O(n)
vector <ll> prime_sieve;
void linear_sieve(ll n)
{
    lin_sieve[0] = lin_sieve[1] = 0;

    for(ll i = 2; i <= n; i++)
    {
        if(lin_sieve[i]) prime_sieve.push_back(i);

        for(auto it : prime_sieve)
        {
            if(it * i > n) break;
            lin_sieve[i*it] = 0;
            if(i % it == 0) break;
        }
    }
}