#include <Template.h>

const int N = 2e5;
int n, m;
vector<pair<int, int>> gr[N];
int vis[N]{0};
vector<int> dis;

void dijkstra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node});
    dis[node] = 0;
    while(!pq.empty())
    {
        auto [co, no] = pq.top();
        pq.pop();
        if(vis[no])
        {
            continue;
        }
        vis[no] = 1;
        for(auto [a, b] : gr[no])
        {
            if(dis[a] > co + b)
            {
                dis[a] = co + b;
                pq.push({dis[a], a});
            }
        }
    }
}