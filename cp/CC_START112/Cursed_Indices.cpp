// https://www.codechef.com/START112B/problems/CURSED
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
    int n;cin>> n;
    vi a(n);cin>>a;
    int sum=0;
    multiset<int> s(all(a));
    vi ans(n);
    int k=0;
    for(int i=0;i<n;i++)
    {
        auto d=(s.upper_bound(sum));
        // cout << sum << " * " << *d << endl;
        if(d==s.end())
            break;
        ans[k++]=*d;
        sum+=*d;
        s.erase(d);
    }
    cout << s.size() << endl;
    // ans.resize(k);
    for(auto x:s)
        ans[k++]=x;
    cout << ans << endl;
    
        
    // sort(all(a));

    
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