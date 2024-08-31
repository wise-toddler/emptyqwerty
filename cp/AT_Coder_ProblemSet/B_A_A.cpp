// https://atcoder.jp/contests/abc327/tasks/abc327_b
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
int pow(int a)
{
    int ans = 1;
    fo1(i,0,a,1)
        ans*=a;
    return ans;
}
vector<int> s;
void solve()
{
    int n;cin>>n;
    fo1(i,0,16,1)
        if(n==s[i])
        {
            cout << (i+1) << endl;
            return;
        }
    cout << "-1" << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    fo1(i,1,16,1)
        s.pb(pow(i));
    while(t--)
    {
        solve();
    }
}