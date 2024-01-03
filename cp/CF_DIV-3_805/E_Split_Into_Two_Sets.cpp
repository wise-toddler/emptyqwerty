// https://codeforces.com/contest/1702/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
bool isBipartite(vector<vector<int>> &edges, int n)
{
    vector<int> colors(n, 0); // 0: not colored, 1: color A, -1: color B

    for (int i = 0; i < n; i++)
    {
        if (colors[i] == 0)
        {
            colors[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : edges[node])
                {
                    if (colors[neighbor] == 0)
                    {
                        colors[neighbor] = -colors[node];
                        q.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[node])
                    {
                        return false; // Conflict, not bipartite
                    }
                }
            }
        }
    }

    return true; // No conflicts, bipartite
}
void solve()
{
    
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}