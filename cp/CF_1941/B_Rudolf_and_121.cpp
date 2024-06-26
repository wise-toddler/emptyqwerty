// https://codeforces.com/contest/1941/problem/B
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
    int n;cin >> n;
    vi a(n);cin >> a;
    fon(i,n-2)
    {
        if(a[i]==0)continue;
        if(a[i]<0)
        {
            cout << "NO" << endl;
            return;
        }
        int k = a[i];
        a[i+1]-=2*k;
        a[i+2]-=k;

        if(a[i+1]<0 || a[i+2]<0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    if(a[n-2]==0 && a[n-1]==0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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
