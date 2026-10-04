#include <Template.h>

const int N = 510; // an initial size of array
int n, m; // global for more usage
int dist[N][N]{0}; // adj matrix for calculating distance 

void floyed()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x, y, c; cin >> x >> y >> c;
        dist[x][y] = min(dist[x][y], c); // undirected graph representation
        dist[y][x] = min(dist[y][x], c);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dist[i][k] == INF) continue;
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // floyed implementation
            }
        }
    }
}

void queries()
{
    int q; cin >> q;
    while(q--)
    {
        int a, b; cin >> a >> b;
        if(dist[a][b] == INF) cout << -1 << nl; // if there is no such path
        else cout << dist[a][b] << nl;
    }
}