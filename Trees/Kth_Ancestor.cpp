#include <Template.h>

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
