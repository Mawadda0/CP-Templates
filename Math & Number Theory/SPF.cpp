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

const int MAX = 1e5;
int SPF[MAX]{}; // SPF[i] = smallest prime factor of i

void precalc_spf()
{
    for(int i = 1; i < MAX; i++)
    {
        SPF[i] = i;
    }
    for(int i = 2; i * i < MAX; i++)
    {
        if(SPF[i] == i)
        {
            for(int j = i * i; j < MAX; j += i)
            {
                if(SPF[j] == j) SPF[j] = i; // assign smallest prime factor for composite number j
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}