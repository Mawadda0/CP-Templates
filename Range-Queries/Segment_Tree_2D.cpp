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

// 2D segment tree for range queries

struct Node
{
    int sum;
    Node()
    {
        sum = 0;
    }
    Node(int x)
    { 
        sum = x; 
    }
    void change(int x)
    { 
        sum = x; 
    }
};

struct segTree2D
{
    int rows, cols;
    vector<vector<Node>> tree;

    segTree2D(int n, int m)
    {
        rows = 1;
        cols = 1;
        while(rows < n) rows *= 2;
        while(cols < m) cols *= 2;
        tree.assign(2 * rows, vector<Node>(2 * cols, Node()));
    }

    Node merge(const Node &lf, const Node &ri)
    {
        return Node(lf.sum + ri.sum);
    }

    void update_y(int ni, int node_y, int ly, int ry, int r, int c, int val, bool is_leaf_x)
    {
        if (ry - ly == 1)
        {
            if(is_leaf_x)
            {
                tree[ni][node_y].change(val);
            }
            else
            {
                tree[ni][node_y] = merge(tree[2 * ni + 1][node_y], tree[2 * ni + 2][node_y]);
            }
            return;
        }
        int mid = (ly + ry) / 2;
        if(c < mid)
        {
            update_y(ni, 2 * node_y + 1, ly, mid, r, c, val, is_leaf_x);
        }
        else
        {
            update_y(ni, 2 * node_y + 2, mid, ry, r, c, val, is_leaf_x);
        }
        tree[ni][node_y] = merge(tree[ni][2 * node_y + 1], tree[ni][2 * node_y + 2]);
    }

    void update_x(int ni, int lx, int rx, int r, int c, int val)
    {
        if (rx - lx > 1)
        {
            int mid = (lx + rx) / 2;
            if(r < mid) update_x(2 * ni + 1, lx, mid, r, c, val);
            else update_x(2 * ni + 2, mid, rx, r, c, val);
        }
        update_y(ni, 0, 0, cols, r, c, val, (rx - lx == 1));
    }

    void update(int r, int c, int val) { update_x(0, 0, rows, r, c, val); }

    Node query_y(int ni, int node_y, int ly, int ry, int c1, int c2)
    {
        if(ly >= c2 || ry <= c1)
        {
            return Node();
        }
        if(ly >= c1 && ry <= c2)
        {
            return tree[ni][node_y];
        }
        int mid = (ly + ry) / 2;
        return merge(query_y(ni, 2 * node_y + 1, ly, mid, c1, c2),
                     query_y(ni, 2 * node_y + 2, mid, ry, c1, c2));
    }

    Node query_x(int ni, int lx, int rx, int r1, int r2, int c1, int c2)
    {
        if(lx >= r2 || rx <= r1)
        {
            return Node();
        }
        if(lx >= r1 && rx <= r2)
        {
            return query_y(ni, 0, 0, cols, c1, c2);
        }

        int mid = (lx + rx) / 2;
        return merge(query_x(2 * ni + 1, lx, mid, r1, r2, c1, c2),
                     query_x(2 * ni + 2, mid, rx, r1, r2, c1, c2));
    }

    int query(int r1, int r2, int c1, int c2)
    {
        return query_x(0, 0, rows, r1, r2, c1, c2).sum;
    }
};


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}