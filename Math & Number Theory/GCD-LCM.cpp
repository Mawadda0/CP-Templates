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

// gcd(a, b) = gcd(a - b, b), if gcd(a, 0) then ans is a

ll gcd(ll a, ll b) // log(n)
{
    if(b > a) swap(a, b);
    if(b == 0) return a;
    return gcd(a % b, b);
} // original was gcd(a - b, b) but mod skips so much substraction like i say x / 2 in every time i implement mod


int gcd(int a, int b) // same method, implemented by recursion
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll gcd(ll a, ll b) // another implementation
{
    while(b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) // lcm using gcd
{
    return (a * b) / gcd(a, b);
}
