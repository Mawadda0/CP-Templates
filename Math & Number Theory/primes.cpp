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
#define min_count(x) order_of_key(x)
#define num_in_pos(x) find_by_order(x)
#define ull unsigned long long

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

bool is_prime(ll n)
{
    if(n == 2) return 1;
    if((n == 0 || n == 1) || n % 2 == 0) return 0;
    for(ll i = 3; i * i <= n; i+= 2)
    {
        if(n % i == 0) return 0;
    }
    return 1;
} // with time O(sqrt(n) / 2)

void solve()
{
    int n; cin >> n;
    cout << (is_prime(n) ? "Prime" : "Not Prime") << nl; // prime checking
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while(tc--)
    {
        solve();
        if (tc) cout << nl;
    }
    return 0;
}