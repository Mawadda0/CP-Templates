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

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}