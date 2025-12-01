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


vector<ll> Divisors(ll n)
{
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++){
        if(n % i == 0){
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    return ret;
} // Divisors

void solve()
{
    int n; cin >> n;
    vector<ll> divs = Divisors(n); // divisors
    for(int i : divs)
    {
        cout << i << " ";
    }
    cout << nl;
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