// https://codeforces.com/gym/514183/problem/I
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
vi cnt,a;
v<v<v<int>>> dp;
bool f(int id,int ch,bool pr)
{
    int &ans=dp[id][ch][pr]; if(ans!=-1) return ans;
    int prval;
    if(id==0) prval=0;
    else if(pr) prval=cnt[ch-1];
    else prval=a[id-1];

    if(id==a.size()) return ans=1;
    if(a[id]>=prval) 
    {
        bool r=0;
        if(ch<2 && cnt[ch]>=prval)
        {
            r|=f(id+1,ch+1,1);
        } 
        r|=f(id+1,ch,0);
        return ans=r;
    }
    if(ch==2) return ans=0;
    int chval=cnt[ch];
    if(chval>=prval)
    {
        if(f(id+1,ch+1,1)) return ans=1;
    }
    return ans=0;
}

void solve()
{
    dp.clear();
    int n,x,y;cin >> n >> x >> y;
    a.resize(n);cin >> a;
    if(x>y) swap(x,y);
    cnt={x,y};
    dp.resize(n+1,v<v<int>>(3,v<int>(3,-1)));
    bool ans=f(0,0,0);
    cout << (ans?"YES":"NO") << endl;

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