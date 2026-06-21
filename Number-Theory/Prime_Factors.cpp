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


vector<ll> factors;
void primes(ll n) // get all prime factors of n (with repetition)
{
    if(n == 1)
    {
        cout << 1 << nl;
        return;
    }

    vector<ll> factors;
    factors.push_back(1);

    while(n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    for(ll i = 3; i * i <= n; i += 2)
    {
        while(n % i == 0){
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 2) factors.push_back(n);
}


vector<pair<ll,ll>> Prime_factors(ll n) // return prime factors with their counts
{
    vector<pair<ll,ll>> res;
    for(ll i = 2; i * i <= n; i++)
    {
        ll c = 0;
        if(n % i == 0)
        {
            while(n % i == 0) n /= i, c++; // count how many times i divides n
            res.push_back({i, c});
        }
    }
    if(n > 1) res.push_back({n, 1});
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}
