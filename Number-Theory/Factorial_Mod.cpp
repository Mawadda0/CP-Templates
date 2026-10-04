#include <Template.h>

const int MAX = 1e5;
vector<ll> fact(MAX); 
const int mod = 998244353;

void precalc_factorial()
{
    fact[0] = 1;// 0! = 1
    for(int i = 1; i < MAX; i++)
    {
        fact[i] = ((fact[i - 1] % mod) * (i % mod)) % mod; // fact[i] = i! % mod
    }
}

// Count occurrences of a prime factor p in n! (Legendre's formula)
ll count_p_in_factorial_n(ll n, ll p)
{
    ll res = 0;
    while(n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}