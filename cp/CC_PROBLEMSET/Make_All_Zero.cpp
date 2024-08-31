// https://www.codechef.com/START115B/problems/MAKE0
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
void print(multiset<int>& ms)
{
    for(auto& x:ms)
        cout<<x<<" ";
    cout<<endl;
}
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    // prefix min
    vi pref(n);
    pref[0]=a[0];
    for(int i=1;i<n;i++)
        pref[i]=min(pref[i-1],a[i]);

    vi idxs;
    fo1(i,n-1,-1,-1)
    {
        if(a[i]==pref[i])
            idxs.pb(a[i]);
    }
    int dop1=idxs.size();
    int ans=n;
    fo1(i,0,dop1,1)
        ans=min(ans,n-i-1+idxs[i]); // (n-i-1) = op2 and idxs{i} = op1
    cout << ans << endl;

    // int op1=0,op2=0;
    // for(int i=n-1;i>=0;i--) {
    //     if(a[i]==pref[i]) 
    //     {
    //         if(pref[i]-op1>i+1)
    //         {
    //             op2+=i+1;
    //             break;
    //         }
    //         op1+=(pref[i]-op1);
    //     }
    //     if(a[i]>op1)
    //         op2++;
    // }
    // cout << min(op1+op2,n) << endl;
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