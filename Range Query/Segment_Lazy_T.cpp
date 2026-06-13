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

template <typename T, typename L>
struct Node
{
    T sum;
    L lazy;
    bool isLazy;

    Node(T neutral_T = T(), L neutral_L = L())
    {
        sum = neutral_T;
        lazy = neutral_L;
        isLazy = false;
    }

    void update(L x, int lx, int rx)
    {
        sum = x * (rx - lx); 
        lazy = x;
        isLazy = true;
    }
};

template <typename T, typename L>
struct segTree
{
    int tree_size;
    vector<Node<T, L>> segData;
    T neutral_T;
    L neutral_L;

    segTree(int n, T neutral_val_T = T(), L neutral_val_L = L())
    {
        neutral_T = neutral_val_T;
        neutral_L = neutral_val_L;
        tree_size = 1;
        while(tree_size < n) tree_size *= 2;
        segData.assign(2 * tree_size, Node<T, L>(neutral_T, neutral_L));
    }

    Node<T, L> merge(Node<T, L> & lf, Node<T, L> & ri)
    {
        Node<T, L> res(neutral_T, neutral_L);
        res.sum = lf.sum + ri.sum;
        return res;
    }

    void propagate(int ni, int lx, int rx)
    {
        if(rx - lx == 1 || !segData[ni].isLazy)
        {
            return;
        }

        int mid = (lx + rx) / 2;
        segData[2 * ni + 1].update(segData[ni].lazy, lx, mid);
        segData[2 * ni + 2].update(segData[ni].lazy, mid, rx);

        segData[ni].isLazy = false;
        segData[ni].lazy = neutral_L;
    }

    void updateP(int l, int r, L val, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if(lx >= r || rx <= l)
        {
            return;
        }

        if(lx >= l && rx <= r)
        {
            segData[ni].update(val, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        updateP(l, r, val, 2 * ni + 1, lx, mid);
        updateP(l, r, val, 2 * ni + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void update(int l, int r, L x)
    {
        updateP(l, r, x, 0, 0, tree_size);
    }

    Node<T, L> getP(int l, int r, int ni, int lx, int rx)
    {
        propagate(ni, lx, rx);
        if(lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if(lx >= r || rx <= l)
        {
            return Node<T, L>(neutral_T, neutral_L);
        }

        int mid = (lx + rx) / 2;
        Node<T, L> left = getP(l, r, 2 * ni + 1, lx, mid);
        Node<T, L> right = getP(l, r, 2 * ni + 2, mid, rx);

        return merge(left, right);
    }

    T get(int l, int r)
    {
        return getP(l, r, 0, 0, tree_size).sum;
    }

    void initP(vector<T> & a, int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < sz(a))
            {
                segData[ni] = Node<T, L>(a[lx], neutral_L);
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
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}