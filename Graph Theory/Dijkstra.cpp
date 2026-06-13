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

const double pi = 3.141592653589793;
const long long INF = 1e18;
const int MOD = 1e9 + 7;

 
// "سُبْحَانَكَ لا عِلْمَ لَنَا إِلَّا مَا عَلَّمْتَنَا إِنَّكَ أَنْتَ الْعَلِيمُ الْحَكِيمُ"
 
const int N = 2e5;
int n, m;
vector<pair<int, int>> gr[N];
int vis[N]{0};
vector<int> dis;

void dijkstra(int node)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, node});
    dis[node] = 0;
    while(!pq.empty())
    {
        auto [co, no] = pq.top();
        pq.pop();
        if(vis[no])
        {
            continue;
        }
        vis[no] = 1;
        for(auto [a, b] : gr[no])
        {
            if(dis[a] > co + b)
            {
                dis[a] = co + b;
                pq.push({dis[a], a});
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    return 0;
}