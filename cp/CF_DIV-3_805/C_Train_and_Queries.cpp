// https://codeforces.com/contest/1702/problem/C
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
#define f0N(i) for(int i=0;i<n;i++)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,q;cin >> n >> q;
    vi a(n);cin >> a;
    map<int,vi> mp;
    f0N(i)
        mp[a[i]].pb(i);
    while(q--)
    {
        int l,r;cin >> l >> r;
        if(!mp[l].size() || !mp[r].size())
        {
            cout << "NO" << endl;
            continue;
        }
        int st=0,en=mp[r].size()-1;
        int ans=-1;
        while(st<=en)
        {
            int mid=(st+en)/2;
            if(mp[r][mid]>mp[l][0])
            {
                ans=mp[r][mid];
                en=mid-1;
            }
            else
                st=mid+1;
        }
        cout << (ans==-1?"NO":"YES") << endl; 
    }
    // set<int> s(all(a));
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