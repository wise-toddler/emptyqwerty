// https://www.codechef.com/START144B/problems/MINIMISEINV
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
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if(count(all(s),'0')<=k || count(all(s),'1')<=k)
    {
        cout << 0 << endl;
        return;
    }
    string ss=s;
    vi c0(n); // count of 0s from i to n-1
    vi c1(n); // count of 1s from 0 to i
    c0[n-1]=s[n-1]=='0';
    c1[0]=s[0]=='1';
    for(int i=n-2;i>=0;i--)c0[i]=c0[i+1]+(s[i]=='0');
    for(int i=1;i<n;i++)c1[i]=c1[i-1]+(s[i]=='1');
    // deb(c0);//
    // deb(c1);
    // use all k op from back then undo 1 from back and do 1 from front
    int kk=k;
    int k0=0,k1=0;
    int nans=0;
    int c=0;
    fon_(i,n) if(ss[i]=='1') nans+=c0[i];
    // deb(nans)
    int cans=0;
    int i=n-1;
    int d=n;
    while(i>=0)
    {
        if(kk and ss[i]=='0') 
            kk--,k0++,d=i;
        else if(ss[i]=='1')
            cans+=c0[i]-k0;       
        i--;
    }
    // deb(cans)
    int ans=nans;
    ans=min(nans,cans);
    // deb(d);
    i=0;
    fon(p,k)
    {
        while(i<n and s[i]=='0') i++;
        cans+=c1[d]-kk;
        // deb(d)
        // deb(cans)
        kk++;
        d++;
        while(d<n and s[d]=='1') d++;
        cans-=c0[i]-(k-kk);
        i++;
        // deb(cans);
        ans=min(ans,cans);
        // nl
    }
    cout <<ans << endl;


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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}