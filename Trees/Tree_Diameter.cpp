#include <Template.h>

class TreeDiameter {
private:
    int n;
    vector<vector<int>> adj;
    int far_node;
    int max_dis;

    void dfs(int node, int parent, int curr)
    {
        if(curr > max_dis)
        {
            max_dis = curr;
            far_node = node;
        }

        for(int child : adj[node])
        {
            if(child != parent)
            {
                dfs(child, node, curr + 1);
            }
        }
    }

public:
    TreeDiameter(int n, const vector<vector<int>> & adj)
    {
        this->n = n;
        this->adj = adj;
    }

    TreeDiameter(int n, const vector<int> & parent)
    {
        this->n = n;
        this->adj.assign(n, vector<int>());
        for(int v = 0; v < n; v++)
        {
            if(parent[v] != -1 && parent[v] != v)
            {
                adj[v].push_back(parent[v]);
                adj[parent[v]].push_back(v);
            }
        }
    }

    int getDiameter()
    {
        if(n <= 1) return 0;
        max_dis = -1;
        far_node = 0;
        dfs(0, -1, 0);
        int start_node = far_node;
        max_dis = -1;
        dfs(start_node, -1, 0);
        return max_dis;
    }
};