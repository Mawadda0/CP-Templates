#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define nl '\n'
#define ll long long
#define int long long
#define fixed(n) fixed << setprecision(n)
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define min_count(x) order_of_key(x)
#define num_in_pos(x) find_by_order(x)
#define ull unsigned long long

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"


vector <bool> sieves(1000001, 1);    // Sieve (Primes From 1 to n)
void sieve(ll n = 1000001)
{
    sieves[0] = sieves[1] = 0;
    for(ll i = 2; i * i <= n; i++){
        if(sieves[i]){
            for(ll j = i * i; j <= n; j += i) sieves[j] = 0;
        }
    }
}

vector <bool> lin_sieve(1e6, 1);            // Linear Sieve O(n)
vector <ll> prime_sieve;
void linear_sieve(ll n) {
    lin_sieve[0] = lin_sieve[1] = 0;

    for (ll i = 2; i <= n; i++) {
        if (lin_sieve[i]) 
        prime_sieve.push_back(i);

        for (auto it : prime_sieve) {
            if (it * i > n)
            break;

            lin_sieve[i*it] = 0;

            if (i % it == 0)
            break;
        }
    }
}