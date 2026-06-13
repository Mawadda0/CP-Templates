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

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

// segment tree for range queries
struct Node
{
    vector<int> v;

    Node() {}

    Node(int x)
    {
        v = {x};
    }
};

struct segTree
{
    int tree_size;
    vector<Node> segData;

    segTree(int n)
    {
        tree_size = 1;
        while(tree_size < n) tree_size *= 2;
        segData.assign(2 * tree_size, Node());
    }

    Node merge(Node &lf, Node &ri)
    {
        Node res;
        res.v.resize(sz(lf.v) + sz(ri.v));

        merge(all(lf.v), all(ri.v), res.v.begin());

        return res;
    }

    void initP(vector<int> &a, int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < sz(a))
                segData[ni] = Node(a[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        initP(a, 2 * ni + 1, lx, mid);
        initP(a, 2 * ni + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void init(vector<int> &a)
    {
        initP(a, 0, 0, tree_size);
    }

    int getP(int l, int r, int x, int ni, int lx, int rx)
    {
        if(lx >= l && rx <= r)
        {
            // int idx = lower_bound(all(segData[ni].v), x) - segData[ni].v.begin();
            //return sz(segData[ni].v) - idx;
            // query: count numbers >= x in range [l, r)

            // int idx = upper_bound(all(segData[ni].v), x) - segData[ni].v.begin();
            //return sz(segData[ni].v) - idx;
            // query: count numbers > x in range [l, r)

            return upper_bound(all(segData[ni].v), x) - segData[ni].v.begin(); 
            // query: count numbers <= x in range [l, r)

            // return lower_bound(all(segData[ni].v), x) - segData[ni].v.begin(); 
            // query: count numbers < x in range [l, r)
        }

        if(lx >= r || rx <= l) return 0;

        int mid = (lx + rx) / 2;

        return getP(l, r, x, 2 * ni + 1, lx, mid) + getP(l, r, x, 2 * ni + 2, mid, rx);
    }

    int get(int l, int r, int x)
    {
        return getP(l, r, x, 0, 0, tree_size);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}