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


const int MAX = 1e5;

int SPF[MAX]{};             // SPF[i] = smallest prime factor of i

void precalc_spf()
{
    for (int i = 1; i < MAX; i++) 
        SPF[i] = i;         // initialize each number as its own smallest prime factor

    for (int i = 2; i * i < MAX; i++) {
        if (SPF[i] == i) {  // i is prime (still marked as itself)
            for (int j = i * i; j < MAX; j += i) {
                if (SPF[j] == j) 
                    SPF[j] = i;   // assign smallest prime factor for composite number j
            }
        }
    }
} // used to precompute the smallest prime factor (SPF) for each number