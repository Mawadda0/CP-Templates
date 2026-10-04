#include <Template.h>
struct Edge
{
    int u, v, w;
};

vector<Edge> read_graph(int m)
{
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    return edges;
}

// Bellman-Ford
void bellman_ford(int n, const vector<Edge> &edges, vector<int> &dist, vector<int> &par)
{
    dist[1] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(auto [u, v, w] : edges)
        {
            if(dist[u] < INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
}


int detect_cycle(int n, const vector<Edge> &edges, vector<int> &dist, vector<int> &par)
{
    int node = -1;

    for(auto [u, v, w] : edges)
    {
        if(dist[u] < INF && dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
            par[v] = u;
            node = v;
        }
    }

    if(node == -1) return -1;
    for(int i = 0; i < n; i++)
    {
        node = par[node];
    }

    return node;
}


vector<int> get_cycle(int start, const vector<int> &par)
{
    vector<int> cycle;
    int cur = start;

    cycle.push_back(cur);
    for(int v = par[cur]; v != start; v = par[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(start);

    reverse(all(cycle));
    return cycle;
}