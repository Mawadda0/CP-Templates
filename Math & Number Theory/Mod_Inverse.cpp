#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define ll long long
#define int long long
#define fixed(n) fixed << setprecision(n)
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define ull unsigned long long

#define sum_mod(a, b, m) (((a % m) + (b % m)) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

const double pi = 3.141592653589793;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

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

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}
