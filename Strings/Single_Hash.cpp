#include <Template.h>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);    
}

struct shash
{
    int base, mod, inv, n;
    vector<ll> pw{1}, invpw{1}, pre{0};
    
    shash(){}
    shash(const string & s, int m, int b)
    {
        base = b;
        n = sz(s);
        mod = m;
        inv = 1;
        ll curr = base;
        int e = mod - 2;
        while(e)
        {
            if(e & 1)
            {
                inv = 1LL * inv * curr % mod;
            }
            (curr *= curr) %= mod;
            e >>= 1;
        }

        for(int i = 0; i < n; i++)
        {
            pw.push_back(pw.back() * base % mod);
            invpw.push_back(invpw.back() * inv % mod);
            pre.push_back((pre.back() + s[i] * pw[i]) % mod);
        }
    }

    ll get(int l, int r)
    {
        return (pre[r + 1] - pre[l] + mod) * invpw[l] % mod;   
    }
};

int rand_base = rand(260, 10000000);
int MOD = 1e9 + 7;