// this code solves problem "E - Lomsat gelral" on CF
// problem link : https://codeforces.com/contest/600/problem/E
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
int c[N], ans[N], sz[N], big[N]; 
int freq[N], freq_sum[N];
int maxi_freq = 0;
vector<pair<int, int>> queries[N]; 

void pre_calc(int u, int p)
{
    sz[u] = 1; 
    for(int v : adj[u])
    {
        if(v == p) continue;
        pre_calc(v, u);
        sz[u] += sz[v];
        if(big[u] == 0 || sz[v] > sz[big[u]])
        {
            big[u] = v;
        } 
    }
}

// update everything here
// remaining functions remain the same
// the solution calc for each node the sum of the maxumum freq colors for each node with subtree
void update(int val, int delta)
{
    freq_sum[freq[val]] -= val;
    freq[val] += delta;
    freq_sum[freq[val]] += val;
    maxi_freq = max(maxi_freq, freq[val]);
}

void collect(int u, int p, int delta)
{
    update(c[u], delta);
    for (int v : adj[u])
    {
        if(v == p) continue;
        collect(v, u, delta);
    }
}


void run_dfs(int u, int p, bool keep)
{
    for(int v : adj[u])
    {
        if(v == p || v == big[u]) continue;
        run_dfs(v, u, false);
    }

    if(big[u] != 0)
    {
        run_dfs(big[u], u, true);
    }


    update(c[u], 1);

    for(int v : adj[u])
    {
        if(v == p || v == big[u]) continue;
        collect(v, u, +1);
    }

    // offline queries "for each query find ..."
    // for(auto [x, i] : queries[u])
    // {
    //     ans[i] = freq[x];
    // }

    // "for each node find .."
    ans[u] = freq_sum[maxi_freq];

    if(!keep)
    {
        collect(u, p, -1);
        maxi_freq = 0; // updated here for erasing
    }
}

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }

    for(int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pre_calc(1, -1);
    run_dfs(1, -1, true);

    for(int i = 1; i <= n; ++i)
    {
        cout << ans[i] << ' ';
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