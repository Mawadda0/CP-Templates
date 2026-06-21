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

    fo (ll i = 2; i <= n; i++)
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


signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}