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
    int mini;
    int maxi;
    int zero_cnt; // for query "find k-th zero"
    Node()
    {
        mini = INF; // the initial value
        maxi = -INF;
        zero_cnt = 0;
    }

    Node(int x)
    {
        mini = x;
        maxi = x;
        zero_cnt = (x == 0 ? 1 : 0);
    }

    void change(int x)
    {
        // mini += x for adding
        mini = x; //for updating
        maxi = x;
        zero_cnt = (x == 0 ? 1 : 0);
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

    // get sum of two nodes, gcd, min or max, or lcm, or whatever yout want to get
    Node merge(Node & lf, Node & ri)
    {
        Node res = Node();
        res.mini = min(lf.mini, ri.mini);
        res.maxi = max(lf.maxi, ri.maxi);
        res.zero_cnt = lf.zero_cnt + ri.zero_cnt;
        return res;
    }

    // ni is the number of the node(tree level by level)
    // lx and rx are the ranges of the node
    // range is from lx to rx, and rx are not included

    void setP(int idx, int val, int ni, int lx, int rx) // 0-indexed , r isn't included
    {
        if(rx - lx == 1)
        {
            segData[ni].change(val);
            return;
        }

        int mid = (lx + rx) / 2;
        if(idx < mid)
        {
            setP(idx, val, 2 * ni + 1, lx, mid);
        }
        else
        {
            setP(idx, val, 2 * ni + 2, mid, rx);
        }

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void set(int idx, int val)
    {
        setP(idx, val, 0, 0, tree_size);
    }

    Node getP(int l, int r, int ni, int lx, int rx) // 0-indexed , r isn't included
    {
        if(lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if(lx >= r || rx <= l)
        {
            return Node();
        }

        int mid = (lx + rx) / 2;
        Node left = getP(l, r, 2 * ni + 1, lx, mid);
        Node right = getP(l, r, 2 * ni + 2, mid, rx);

        return merge(left, right);
    }

    int get_min(int l, int r)
    {
        return getP(l, r, 0, 0, tree_size).mini;
    }

    int get_max(int l, int r)
    {
        return getP(l, r, 0, 0, tree_size).maxi;
    }

    void initP(vector<int> & a, int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < sz(a))
            {
                segData[ni] = Node(a[lx]);
            }
 
            return;
        }
        int mid = (lx + rx) / 2;
        initP(a, 2 * ni + 1, lx, mid);
        initP(a, 2 * ni + 2, mid, rx);
 
        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }
 
    void init(vector<int> & a)
    {
        initP(a, 0, 0, tree_size);
    }

    int find_kth_zero_P(int k, int ni, int lx, int rx) // find k-th zero
    {
        if(segData[ni].zero_cnt < k) return -1;

        if(rx - lx == 1)
        {
            return lx;
        }

        int mid = (lx + rx) / 2;
        int left_zeros = segData[2 * ni + 1].zero_cnt;

        if(k <= left_zeros)
        {
            return find_kth_zero_P(k, 2 * ni + 1, lx, mid);
        }
        else
        {
            return find_kth_zero_P(k - left_zeros, 2 * ni + 2, mid, rx);
        }
    }

    int find_kth_zero(int k)
    {
        return find_kth_zero_P(k, 0, 0, tree_size);
    }

    int get_first_P(int l, int r, int x, int ni, int lx, int rx) // first element and comparing with x, first index and compering with x
    {
        if(lx >= r || rx <= l) return -1;

        // if(segData[ni].maxi <= x) return -1; // if we want to search on first element/a[idx] greater than x
        if(segData[ni].maxi < x) return -1; // if we want to search on first element/a[idx] greater or equal x
        // if(segData[ni].mini >= x) return -1; // if we want to search on first element/a[idx] less than x
        // if(segData[ni].mini > x) return -1; // if we want to search on first element/ a[idx] less or equal than x


        if(rx - lx == 1) return lx;

        int mid = (lx + rx) / 2;
        int left = get_first_P(l, r, x, 2 * ni + 1, lx, mid);
        if(left != -1) return left;
        return get_first_P(l, r, x, 2 * ni + 2, mid, rx);
    }

    int get_first(int l, int r, int x)
    {
        return get_first_P(l, r, x, 0, 0, tree_size);
    }


};


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}