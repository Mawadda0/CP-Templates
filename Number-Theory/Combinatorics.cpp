#include <Template.h>

ll gcd(ll a, ll b)
{
    while(b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

const int N = 2e6 + 10;
int fact[N], inv[N], factInv[N];

void precalc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
    {
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
    }

    inv[1] = 1;
    for(int i = 2; i < N; i++)
    {
        inv[i] = ((MOD - (MOD / i)) % MOD * (inv[MOD % i] % MOD)) % MOD;
    }

    factInv[0] = 1;
    for(int i = 1; i < N; i++)
    {
        factInv[i] = ((factInv[i - 1] % MOD) * (inv[i] % MOD)) % MOD;
    }

}

int npr(int n, int r)
{
    if(r > n) return 0;
    return ((fact[n] % MOD) * (factInv[n - r] % MOD)) % MOD;
}

int ncr(int n, int r)
{
    return ((npr(n, r) % MOD) * (factInv[r] % MOD)) % MOD;
}

int modpow(int a, int b)
{
    int res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}