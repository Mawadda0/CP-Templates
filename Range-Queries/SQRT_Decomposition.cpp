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

class SqrtDecomposition {
private:
    int n;
    int SQ;
    vector<int> blk;
    vector<vector<int>> b;
    vector<int> a;

    void process()
    {
        for(int i = 0; i < n; i++)
        {
            b[i / SQ].push_back(a[i]);
            blk[i / SQ] += a[i]; // change here : summation
        }
    }

public:
    SqrtDecomposition(int n, const vector<int> & a)
    {
        this->n = n;
        this->SQ = sqrt(n) + 1;
        this->a = a;
        blk.assign(SQ, 0);
        b.resize(SQ);
        process();
    }

    void update(int idx, int x)
    {
        blk[idx / SQ] -= a[idx]; // change here : summation
        blk[idx / SQ] += x; // change here : summation 
        b[idx / SQ][idx % SQ] = x;
        a[idx] = x;
    }

    int query(int l, int r)
    {
        int res = 0;
        while(l <= r)
        {
            if (l % SQ == 0 && l + SQ <= r)
            {
                res += blk[l / SQ]; // change here : summation
                l += SQ;
            }
            else
            {
                res += a[l]; // change here : summation
                l++;
            }
        }
        return res;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}