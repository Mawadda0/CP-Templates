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
#define ld long double

const double pi = 3.141592653589793;
const long long INF = 2e18;
const int MOD = 1e9 + 7;

// سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ

// finweck and 2d finweck are sutable for inverse operations (sum, xor, product)
// all comments with "changes here" if we need to use template with any operation instead of summation
class FenwickTree {
private:
    vector<int> bit;  // binary indexed tree
    int n;

public:
    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n + 5, 0); // identity element (for sum : 0), (for product : 1), (for xor : 0)
    }

    FenwickTree(vector<int> const &a) : FenwickTree(sz(a))
    {
        for (int i = 0; i < n; i++)
        {
            bit[i] += a[i]; // changes here
            int nxt = i | (i + 1);
            if(nxt < n) bit[nxt] += bit[i]; // changes here
        }
    }

    void add(int idx, int x)
    {
        for(; idx < n; idx = idx | (idx + 1))
        {
            bit[idx] += x; // changes here
        }
    }

    int sum_query(int r) // prefix sum from 0 to r
    {
        int ret = 0;
        for(; r >= 0; r = (r & (r + 1)) - 1)
        {
            ret += bit[r]; // changes here
        }
        return ret;
    }

    int sum_query(int l, int r) // sum on range [l, r]
    {
        if(l > r) return 0; // identity element
        if(l == 0) return sum_query(r);
        return sum_query(r) - sum_query(l - 1);
    }

    // in product query, we should use ModInverse when updating and quering

    void update(int idx, int x)
    {
        int curr = sum_query(idx, idx);
        int delta = x - curr;
        add(idx, delta);
    }

    // lower & upper bound using binary lifting
    int lower_bound(int x) // returns lowest index with sum >= x
    {
        int idx = -1, mask = 1;
        while(mask < n)
        {
            mask <<= 1;
        }
        for(; mask > 0; mask >>= 1)
        {
            int nxt = idx + mask;
            if(nxt < n && bit[nxt] < x)
            {
                x -= bit[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }

    int upper_bound(int x) // returns lowest index with sum > x
    {
        int idx = -1, mask = 1;
        while(mask < n)
        {
            mask <<= 1;
        }
        for(; mask > 0; mask >>= 1)
        {
            int nxt = idx + mask;
            if(nxt < n && bit[nxt] <= x)
            {
                x -= bit[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
    // benefits that we are calculating the lower and upper within O(log n) instead of using Binary search with regular prefix with O(log^ n)
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}