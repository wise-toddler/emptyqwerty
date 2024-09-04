// https://codeforces.com/contest/1951/problem/B
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
int run(vi &a, int id)
{
    int n=a.size();
    vi win(n,0);
    int c=0;
    if(a[1]>a[0]) c=1;
    int cnt=1;
    win[c]=1;
    fo1(i,2,n,1)
    {
        if(a[c]<a[i])
        {
            win[c]=cnt;
            c=i;
            cnt=0;
        }
        cnt++;
    }
    win[c]=cnt;
    return win[id];
}
void solve()
{
    int n,id; cin >> n >> id;
    id--;
    vi a(n); cin >> a;
    int i=0;
    int cnt=0;
    int k=-1;
    while(i<id)
    {
        if(a[i]>a[id]) 
        {
            k=i;
            break;
        }
        i++;
    }
    int ans=run(a,id);
    swap(a[0],a[id]);
    ans=max(ans,run(a,0));
    if(k==-1)
    {
        cout << ans << endl;
        return;
    }
    swap(a[id],a[0]);
    swap(a[k],a[id]);
    ans=max(ans,run(a,k));
    cout << ans << endl;
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