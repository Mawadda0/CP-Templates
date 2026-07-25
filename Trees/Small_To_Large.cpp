// this code solve problem distinct colors on cses
// problem link : https://cses.fi/problemset/task/1139
#include <bits/stdc++.h>
 
using namespace std;

#define nl '\n'
#define ll long long
#define int long long
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define fixed(n) fixed << setprecision(n)
#define ull unsigned long long
#define ld long double
#define memo(dp, val) memset(dp, val, sizeof(dp))
 
const double pi = 3.141592653589793;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ
 
const int N = 2e5 + 5;
 
 
vector<int> adj[N];
set<int> st[N];
vector<int> a, res;
 
void dfs(int u, int p)
{
    st[u].insert(a[u]);
    for(int v : adj[u])
    {
        if(v == p) continue;
        dfs(v, u);
        if(sz(st[v]) > sz(st[u])) swap(st[v], st[u]);
        for(int col : st[v])
        {
            st[u].insert(col);
        }
    }
    res[u] = sz(st[u]);
}

void solve()
{
    int n; cin >> n;
    a.resize(n + 1);
    res.resize(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i < sz(res); i++)
    {
        cout << res[i] << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        solve();
        if(tc) cout << nl;
    }
    return 0;
}