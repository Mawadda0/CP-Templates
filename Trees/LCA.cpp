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

const double pi = 3.141592653589793;
const long long INF = 2e18;
const int MOD = 1e9 + 7;

// سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ

class TreeAncestor {
private:
    int n;
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    
    void build(vector<int> & parent)
    {
        for(int node = 0; node < n; node++)
        {
            up[node][0] = parent[node];
            if(node != 0 && parent[node] != -1)
            {
                depth[node] = depth[parent[node]] + 1;
            }
        }

        for(int j = 1; j < LOG; j++)
        {
            for(int node = 0; node < n; node++)
            {
                if(up[node][j - 1] != -1)
                {
                    up[node][j] = up[ up[node][j - 1] ][j - 1];
                }
            }
        }
    }

    void dfs(int node, int p, int d, const vector<vector<int>> & adj, vector<int> & parent)
    {
        parent[node] = p;
        depth[node] = d;
        for(int child : adj[node])
        {
            if(child != p)
            {
                dfs(child, node, d + 1, adj, parent);
            }
        }
    }

public:
    TreeAncestor(int n, vector<int> & parent)
    {
        this->n = n;
        this->LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1)); 
        depth.assign(n, 0);

        build(parent);
    }

    TreeAncestor(int n, int root, const vector<vector<int>> & adj)
    {
        this->n = n;
        this->LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1)); 
        depth.assign(n, 0);

        vector<int> parent(n, -1);
        dfs(root, -1, 0, adj, parent);
        build(parent);
    }
    
    int getKthAncestor(int node, int k)
    {
        for(int j = 0; j < LOG; j++)
        {
            if(k & (1 << j))
            {
                node = up[node][j];
                if(node == -1) return -1;
            }
        }
        return node;
    }

    int getLCA(int a, int b)
    {
        if(depth[a] < depth[b])
        {
            swap(a, b);
        }
        a = getKthAncestor(a, depth[a] - depth[b]);
        if(a == b)
        {
            return a;
        }
        for(int j = LOG - 1; j >= 0; j--)
        {
            if(up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    }
};


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}