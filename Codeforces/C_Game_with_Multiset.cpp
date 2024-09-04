// https://codeforces.com/contest/1913/problem/C
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
    vi a(30);
    int t;cin>>t;
    while(t--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int x;cin>>x;
            a[x]++;
        }
        else
        {
            int x;cin>>x;
            fo1(i,29,-1,-1)
            {
                int t = min(x>>i,a[i]);
                x-=t<<i;
            }
            cout << (x==0?"YES":"NO") << endl;
        }
    }
}
signed main()
{
    IOS
    // TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}