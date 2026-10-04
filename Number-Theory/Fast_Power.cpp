#include <Template.h>

ll fastpower(ll base, ll exp) // (base ^ exp)
{
    ll res = 1;
    while(exp)
    {
        if(exp & 1) res *= base;
        base *= base;
        exp >>= 1ll;
    }
    return res;
}

ll modpow(ll base, ll exp, ll mod) // (base ^ exp) % mod
{
    base %= mod;
    ll res = 1;
    while(exp)
    {
        if(exp & 1) res = (res * base) % mod;
        base = ((base % mod) * (base % mod)) % mod;
        exp >>= 1ll;
    }
    return res;
}
// used for modular inverse: a ^ (mod - 2) % mod when mod is prime
