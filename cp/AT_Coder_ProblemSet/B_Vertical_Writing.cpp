// https://atcoder.jp/contests/abc366/tasks/abc366_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << '\n';return os;}
void solve()
{
    int n;cin >> n;
    v<string> s(n); cin >> s;
    v<string> ans;
    int maxl=0;
    for(int i=0;i<n;i++)
    {
        maxl=max(maxl,(int)s[i].size());
    }
    for(int i=0;i<maxl;i++)
    {
        string temp;
        for(int j=n-1;j>=0;j--)
        {
            if(i<s[j].size())
            {
                temp+=s[j][i];
            }
            else
            {
                temp+='*';
            }
        }
        // trim trailing *
        while(temp.back()=='*') temp.pop_back();
        ans.pb(temp);
    }
    cout << ans;

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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}