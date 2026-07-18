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
#define memo(dp, val) memset(dp, val, sizeof(dp))

const double pi = 3.141592653589793;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ

// number of unique elements in subarray [l, r]
// note that everything isn't changable 
// add , remove, consts line N, SQ is the only thing that will change

const int N = 3e4 + 5, SQ = 175, M = 2e5 + 5, S = 1e6 + 6;
int n, q, res = 0;
int vis[S];
vector<int> a;

struct Query
{
    int l, r, q_idx, blk_idx;
    Query(){}
    Query(int l, int r, int q_idx)
    {
        this->l = l;
        this->r = r;
        this->q_idx = q_idx;
        blk_idx = l / SQ;
    }

    bool operator<(const Query & Q) const 
    {
        if(blk_idx != Q.blk_idx)
        {
            return blk_idx < Q.blk_idx;    
        }
        return r < Q.r;
    } 
};

Query qu[M];
int ans[M];


void add(int idx)
{
    if(!vis[a[idx]]) res++;
    vis[a[idx]]++;
}

void remove(int idx)
{
    vis[a[idx]]--;
    if(!vis[a[idx]]) res--;
}

void MO_process()
{
    sort(qu, qu + q);
    int l = 0, r = -1;
    for(int i = 0; i < q; i++)
    {
        while(l > qu[i].l) add(--l);
        while(r < qu[i].r) add(++r);

        while(l < qu[i].l) remove(l++);
        while(r > qu[i].r) remove(r--);
        ans[qu[i].q_idx] = res;
    }
    while(r >= l) remove(r--); // to avoid reset vis array in main if problem contains test cases.
}


void solve()
{
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;
        l--, r--;
        qu[i] = Query(l, r, i);
    }
    MO_process();
    for(int i = 0; i < q; i++)
    {
        cout << ans[i] << nl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        solve();
        if(tc) cout << nl;
    }
    return 0;
}