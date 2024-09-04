// https://codeforces.com/gym/496831/problem/G
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
int check(vi &a,int k,int s,int m)
{
    int n=a.size();
    int c=0;
    int maxinaset=0;
    for(int i=0;i<n;i++)
    {
        int sc=0;
        int j=i;
        while(sc<s && (i+sc)<n && (a[i+sc]-a[i])<=m)
        {
            maxinaset=max(maxinaset,a[i+sc]-a[i]);
            sc++;
        }
        c++;
        i=j+sc-1;
    }
    return (c<=k)?(maxinaset):(-1);
}
void solve()
{
    int n,k,s;cin>>n>>k>>s;
    vi a(n);cin>>a;
    sort(all(a));
    int ans=0;
    for(int i=0;i<n;i+=s)
        ans=max(ans,a[i+s-1]-a[i]);
    
    // 1 1 3 4 10 14
    
    int l=0,r=a[n-1]-a[0];
    while(l<=r)
    {
        int m=(l+r)/2;
        int cans=check(a,k,s,m);
        if(cans!=-1)
        {
            ans=cans;
            r=m-1;
        }
        else
            l=m+1;
    }
    cout << ans << endl;
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