#include <Template.h>

class sparseTable
{
private:
    int n, Log;
    vector<vector<int>> T;
    int skip = INF; // initial value

    int merge(int a, int b)
    {
        return min(a, b);
    }

public:

    void build(vector<int> & a)
    {
        n = sz(a);
        Log = 64 - __builtin_clzll(n);
        T.assign(n, vector<int>(Log, 0));
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