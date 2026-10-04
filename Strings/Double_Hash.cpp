#include <Template.h>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);    
}

struct dhash
{
    int base1, mod1, inv1, n;
    int base2, mod2, inv2;
    vector<ll> pw1{1}, invpw1{1}, pre1{0};
    vector<ll> pw2{1}, invpw2{1}, pre2{0};
    
    dhash(){}
    dhash(const string & s, int m1, int m2, int b1, int b2)
    {
        n = sz(s);
        base1 = b1, base2 = b2;
        mod1 = m1, mod2 = m2;

        inv1 = 1, inv2 = 1;
        ll curr1 = base1, curr2 = base2;
        int e1 = mod1 - 2, e2 = mod2 - 2;
        while(e1)
        {
            if(e1 & 1)
            {
                inv1 = 1LL * inv1 * curr1 % mod1;
            }
            (curr1 *= curr1) %= mod1;
            e1 >>= 1;
        }

        while(e2)
        {
            if(e2 & 1)
            {
                inv2 = 1LL * inv2 * curr2 % mod2;
            }
            (curr2 *= curr2) %= mod2;
            e2 >>= 1;
        }

        for(int i = 0; i < n; i++)
        {
            pw1.push_back(pw1.back() * base1 % mod1);
            invpw1.push_back(invpw1.back() * inv1 % mod1);
            pre1.push_back((pre1.back() + s[i] * pw1[i]) % mod1);

            pw2.push_back(pw2.back() * base2 % mod2);
            invpw2.push_back(invpw2.back() * inv2 % mod2);
            pre2.push_back((pre2.back() + s[i] * pw2[i]) % mod2);
        }
    }

    pair<ll, ll> get(int l, int r)
    {
        return {(pre1[r + 1] - pre1[l] + mod1) * invpw1[l] % mod1,
                (pre2[r + 1] - pre2[l] + mod2) * invpw2[l] % mod2};   
    }
};

int rand_base1 = rand(260, 10000000);
int rand_base2 = rand(260, 10000000);
int MOD1 = 1e9 + 7;
int MOD2 = 1e9 + 9;