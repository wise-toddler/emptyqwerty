// https://atcoder.jp/contests/abc327/tasks/abc327_a
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
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='a' && s[i+1]=='b' || s[i]=='b' && s[i+1]=='a')
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;

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