#include <Template.h>

template <int N, int M>
struct ForwardStar
{
    //In case of weighted graph, put back all removed w.
    int head[N];
    int to[M];
    int nxt[M];
    //int wt[M];
    int ne;

    void init(int n)
    {
        ne = 0;
        fill(head, head + n + 1, -1); 
    }

    // Removed the 'int w' parameter
    void addEdge(int u, int v)
    {
        to[ne] = v;
        //wt[ne] = w;
        nxt[ne] = head[u];
        head[u] = ne++;
    }

    // Removed the 'int w' parameter
    void addBiEdge(int u, int v)
    {
        addEdge(u, v);
        addEdge(v, u);
    }

    void traverse(int u)
    {
        cout << "Neighbors of node " << u << ": ";

        for(int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e];
            //int w = wt[e];
            cout << v << " ";
        }
        cout << nl;
    }
};