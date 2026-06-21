#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define ll long long
#define int long long
#define fixed(n) fixed << setprecision(n)
#define sz(x) (int)(x.size())
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define ull unsigned long long

const double pi = 3.141592653589793;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"

template <typename T>
struct Node
{
    T val;

    Node()
    {
        val = 0; // for char '' and for string ""
    }

    Node(T x)
    {
        val = x;
    }

    void change(T x)
    {
        val = x;
    }
};


template <typename T>
struct segTree
{
    int tree_size;
    vector<Node<T>> segData; 
    T neutral_element; // 0 for sum, INF for min, -INF for max ..

    segTree(int n, T neutral)
    {
        neutral_element = neutral;
        tree_size = 1;
        while(tree_size < n) tree_size *= 2;
        
        segData.assign(2 * tree_size, Node<T>(neutral_element));
    }

    Node<T> merge(Node<T> & lf, Node<T> & ri)
    {
        Node<T> res = Node<T>();
        res.val = lf.val + ri.val;
        return res;
    }

    void setP(int idx, T val, int ni, int lx, int rx) 
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

    void set(int idx, T val)
    {
        setP(idx, val, 0, 0, tree_size);
    }

    Node<T> getP(int l, int r, int ni, int lx, int rx) 
    {
        if(lx >= l && rx <= r)
        {
            return segData[ni];
        }
        if(lx >= r || rx <= l)
        {
            return Node<T>(neutral_element);
        }

        int mid = (lx + rx) / 2;
        Node<T> left = getP(l, r, 2 * ni + 1, lx, mid);
        Node<T> right = getP(l, r, 2 * ni + 2, mid, rx);

        return merge(left, right);
    }

    T get(int l, int r)
    {
        return getP(l, r, 0, 0, tree_size).val;
    }

    void initP(vector<T> & a, int ni, int lx, int rx)
    {
        if(rx - lx == 1)
        {
            if(lx < sz(a))
            {
                segData[ni] = Node<T>(a[lx]);
            }
            return;
        }
        int mid = (lx + rx) / 2;
        initP(a, 2 * ni + 1, lx, mid);
        initP(a, 2 * ni + 2, mid, rx);

        segData[ni] = merge(segData[2 * ni + 1], segData[2 * ni + 2]);
    }

    void init(vector<T> & a)
    {
        initP(a, 0, 0, tree_size);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}