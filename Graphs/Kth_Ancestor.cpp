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
    
    void build(vector<int> & parent)
    {
        for(int node = 0; node < n; node++)
        {
            up[node][0] = parent[node];
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

    void dfs(int node, int p, const vector<vector<int>> & adj, vector<int> & parent)
    {
        parent[node] = p;
        for(int child : adj[node])
        {
            if(child != p)
            {
                dfs(child, node, adj, parent);
            }
        }
    }

public:
    TreeAncestor(int n, vector<int> & parent)
    {
        this->n = n;
        this->LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1)); 
        
        build(parent);
    }

    TreeAncestor(int n, int root, const vector<vector<int>> & adj)
    {
        this->n = n;
        this->LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1)); 

        vector<int> parent(n, -1);
        dfs(root, -1, adj, parent);
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
};


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}