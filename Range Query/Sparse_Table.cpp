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

const int INF = 2e18;

// سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ


class sparseTable
{
private:
    const int N = 2e5 + 5, Log = 23;
    vector<vector<int>> T;
    int skip = INF; // initial value

    int merge(int a, int b)
    {
        return min(a, b);
    }

public:
    sparseTable()
    {
        T.assign(N, vector<int>(Log, 0));
    }

    void build(vector<int> & a)
    {
        int n = sz(a);
        for(int i = 0; i < n; i++)
        {
            T[i][0] = a[i];
        }

        for(int pw = 1; (1LL << pw) <= n; pw++) // powers of 2
        {
            for(int i = 0; i + (1LL << pw) <= n; i++) // elements
            {
                T[i][pw] = merge(T[i][pw - 1], T[i + (1LL << (pw - 1))][pw - 1]);
            }
        }
    }

    // O(log N)
    int query(int l, int r)
    {
        int len = r - l + 1;
        int res = skip;

        for(int pw = Log - 1; pw >=0; pw--)
        {
            if((len >> pw) & 1LL)
            {
                res = merge(res, T[l][pw]);
                l += (1LL << pw);
            }
        }
        return res;
    }

    // O(1)
    // works with: min, max, gcd, lcm, or, and
    // doesn't work with: sum, product, subtraction, xor
    int fast_query(int l, int r)
    {
        int len = r - l + 1;
        int lg = 63 - __builtin_clzll(len);
        return merge(T[l][lg], T[r - (1LL << lg) + 1][lg]);
    }

};


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}