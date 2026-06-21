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

const double pi = 3.141592653589793;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

const int N = 2e5 + 5;
vector<vector<int>> adj; // holdes the nodes and their adjacency

void graph_rep(int n, int m)
{
    adj.assign(n + 1, {});
    int u, v, t;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> t;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> vis;
vector<int> color;
bool cycle = false;

void dfs(int node)
{
    vis[node] = 1;
    for(int ni : adj[node])
    {
        if(!vis[ni]) dfs(ni);
    }
 
}


void dfs_tree(int u, int p)
{ // for a tree (just parent and child relationship)
    for(int v : adj[u])
    {
        if(v == p) continue;
        dfs_tree(v, u);
    }
}


int dfsCount(int u)
{  // count components (neighbors and neighbors of the neighbors) for a node
    vis[u] = 1;
    int cnt = 1;
    for(int v : adj[u])
    {
        if(!vis[v]) 
        cnt += dfsCount(v);
    }
    return cnt;
}

bool dfs_cycle(int u)
{
    color[u] = 1; // GRAY
    for(int v : adj[u])
    {
        if(color[v] == 0)
        {
            if(dfs_cycle(v)) return true;
        }
        else if(color[v] == 1) return true;
    }
    color[u] = 2; // BLACK
    return false;
}

string grid[2001];
bool vis2d[2001][2001];
int di[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dj[] = {0, 0, -1, 1, -1, 1, -1, 1};
int rows, cols;

bool is_valid(int r, int c)
{
    return (r >= 0 && r < rows && c >= 0 && c < cols && !vis2d[r][c] && grid[r][c] == '.');
}


void dfs_grid(int r, int c)
{
    vis2d[r][c] = true;
    for(int k = 0; k < 4; k++)
    {
        int nr = r + di[k];
        int nc = c + dj[k];
        if(is_valid(nr, nc)) dfs_grid(nr, nc);
    }
}

int dfsDepth(int u)
{
    int maxx = 0;
    for(auto v : adj[u])
    {
        maxx = max(maxx, dfsDepth(v));
    }
    return maxx + 1;
}

vector<int> topo;
vector<int> visTopo;

void dfs_topo(int u)
{
    visTopo[u] = 1;
    for(int v : adj[u])
    {
        if(!visTopo[v])
            dfs_topo(v);
    }
    topo.push_back(u); 
}

vector<int> topological_sort(int n)
{
    visTopo.assign(n + 1, 0);
    topo.clear();

    for(int i = 1; i <= n; i++)
    {
        if(!visTopo[i])
            dfs_topo(i);
    }

    reverse(topo.begin(), topo.end());
    return topo;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}