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

const double pi = 3.141592653589793;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

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

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}