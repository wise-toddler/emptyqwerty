// https://www.codechef.com/START113B/problems/SUMNEQ7
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    map<int,int> mp;
    int ans=0;
    int j=0;
    for(int i:a)
        mp[i]++;
    if(n==4)
    {
        cout << ((a[0]+a[1]!=a[2]+a[3])?"YES":"NO") << endl; 
        return;
    }
    if(mp.size()==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(mp.size()>1)
    {
        cout<<"YES"<<endl;
        return;
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