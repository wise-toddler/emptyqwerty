// https://atcoder.jp/contests/abc332/tasks/abc332_b
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
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int k,g,m;cin >> k >> g >> m;
    int ch = ceil((double)g/m);
    int ans = 0;
    int am=0,ag=0;
    while(k--)
    {
        if(ag==g)
        {
            // cout << 1 << " ";
            ag=0;
        }
        else if(am==0)
        {
            // cout << 2 <<" " ;
            am=m;
            // ag=0;
        }
        else 
        {
            // cout << 3 << " ";
            if(g-ag>=am)
            {
                ag+=am;
                am=0;
            }
            else
            {
                am-=(g-ag);
                ag=g;
            }
        }
    }
        cout << ag << " " << am << endl;
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