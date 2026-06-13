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

const int MAXI = 5e5 + 5;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

struct DSU
{
    vector<int> parent, group;
    int comps, maxi_comp_size;

    struct operation
    {
        int a, sizeA, b, sizeB, old_maxi;
    };
    stack<operation> ops;

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
        return find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if(a == b) return false;    
        if(group[a] < group[b]) swap(a, b);

        ops.push({a, group[a], b, group[b], maxi_comp_size});

        group[a] += group[b];
        parent[b] = a;
        comps--;
        maxi_comp_size = max(maxi_comp_size, group[a]);

        return true;
    }

    void rollback()
    {
        if(ops.empty()) return;

        auto op = ops.top();
        ops.pop();

        int a = op.a;
        int b = op.b;

        parent[b] = b;
        group[a] = op.sizeA;
        group[b] = op.sizeB;
        maxi_comp_size = op.old_maxi;
        comps++;
    }

    void rollback_k_times(int k)
    {
        while(k-- && !ops.empty())
        {
            rollback();
        }
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

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}
