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


// gcd(a, b) = gcd(a - b, b), if gcd(a, 0) then ans is a
ll gcd(ll a, ll b) // log(n)
{
    if(b > a) swap(a, b);
    if(b == 0) return a;
    return gcd(a % b, b);
} // original was gcd(a - b, b) but mod skips so much substraction like i say x / 2 in every time i implement mod

int gcd(int a, int b) // same method, implemented by recursion
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll gcd(ll a, ll b) // another implementation
{
    while(b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) // lcm using gcd
{
    return (a * b) / gcd(a, b);
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}
