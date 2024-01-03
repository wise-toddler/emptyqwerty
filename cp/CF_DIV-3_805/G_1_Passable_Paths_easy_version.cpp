// https://codeforces.com/contest/1702/problem/G1
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

vi lon;
bool isEulerPathPossible(vector<int>& path, unordered_map<int,set<int>>& adjList ,int np,int st,int papa=0)
{
    
}
void solve()
{
    int n;cin >> n;
    // take n-1 edges
    vector<pii> edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin >> a >> b;
        edges[i]={a,b};
    }

    unordered_map<int, set<int>> adjList;
    for (const auto& edge : edges) 
    {
        adjList[edge.first].insert(edge.second);
        adjList[edge.second].insert(edge.first);
    }
    for(auto i:adjList)
        if(i.second.size()==1)
            lon.pb(i.first);

    int q;cin >> q;
    while (q--)
    {
        int pl;cin >> pl;
        vi p(pl);cin >> p;
        for(auto i:lon)
        {
            int np=p.size();
            if(isEulerPathPossible(p, adjList,np,i)) 
            {
                cout << "YES" << endl;
                break;
            }
        }
            
        // cout << (isEulerPathPossible(p, degree) ? "YES" : "NO") << endl; 

    }
    
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}