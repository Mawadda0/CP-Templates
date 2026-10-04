#include <Template.h>

ll ext_euclidean_gcd(ll a, ll b, ll &x, ll &y) // Extended Euclidean Algorithm,  Solves ax + by = gcd(a, b)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ext_euclidean_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ll mod_inverse(ll b, ll m) // --> find a / b & mod
{
    ll x, y;
    ll g = ext_euclidean_gcd(b, m, x, y);
    if(g != 1) return -1;
    return (x % m + m) % m; // normalize x to positive mod
}

int mod_inverse_bf(int A, int M) // brute-force modular inverse
{
    for(int X = 1; X < M; X++)
    {
        if(((A % M) * (X % M)) % M == 1) return X;
    }
    return -1;
}