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
#define min_count(x) order_of_key(x)
#define num_in_pos(x) find_by_order(x)
#define ull unsigned long long

const double pi = 3.141592653589793;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

struct DSU
{
    vector<int> parent, group;
    int comps, maxi_comp_size;


    DSU(int n)
    {
        parent.resize(n);
        group.resize(n);
        comps = n, maxi_comp_size = 1;
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            group[i] = 1;
        }
    }

    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b) return false;    
        if(group[a] < group[b]) swap(a, b);

        group[a] += group[b];
        parent[b] = a;
        comps--;
        maxi_comp_size = max(maxi_comp_size, group[a]);
        return true;
    }

    bool same_set(int a, int b)
    {
        return find(a) == find(b);
    }

    int get_size(int x)
    {
        return group[find(x)];
    }

};

int n, m; 
vector<tuple<int, int, int>> edg;

void kruskal()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        u--;
        v--;
        edg.push_back({w, u, v});
    }

    sort(all(edg));
    DSU dsu(n);
    int mst = 0; // Total weight of Minimum Spanning Tree
        for(auto & [w, u, v] : edg)
    {
        if(dsu.unite(u, v)) mst += w;
    }
    cout << mst;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}