// https://codeforces.com/contest/1800/problem/C1
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
void solve()
{
    int n;cin >> n;
    vi v(n);
    fo1(i,0,n,1) cin >> v[i];
    int ans = 0;
    multiset<int> s;
    fo1(i,0,n,1)
    {
        if(s.size()==0)
        {
            s.insert(v[i]);
            continue;
        }
        if(v[i]==0)
        {
            auto it = s.end();
            it--;
            ans+=*it;
            s.erase(it);
        }
        else 
            s.insert(v[i]);
    }   
    cout << ans << endl;
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