// https://www.codechef.com/START142B/problems/LENGTHX
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

class segtre
{
public:
    int n;
    int idn;
    vi t;
    segtre(int n,int idn)
    {
        this->n=n;
        this->idn=idn;
        t.assign(4*n,idn);
    }
    int merge(int a,int b)
    {
        return a+b;
    }
    void up(int id,int val)
    {
        function<void(int,int,int)> up = [&](int tid,int l,int r)
        {
            if(l==r)
            {
                t[tid]+=val;
                return;
            }
            int m=(l+r)/2;
            if(id<=m) up(2*tid+1,l,m);
            else up(2*tid+2,m+1,r);
            t[tid]=merge(t[2*tid+1],t[2*tid+2]);
        };
        up(0,0,n-1);
    }
    int query(int l,int r)
    {
        function<int(int,int,int)> query = [&](int id,int ll,int rr)
        {
            if(r<ll || l>rr) return idn;
            if(l<=ll && rr<=r) return t[id];
            int m=(ll+rr)/2;
            return merge(query(2*id+1,ll,m),query(2*id+2,m+1,rr));
        };
        return query(0,0,n-1);
    }
};
void solve()
{
    int n,x;cin >> n >> x;
    vi a(n);cin >> a;
    set<int> s(all(a));
    vi b = vi(all(s));
    vi p;
    for(int i=0,k=1;i<=19;i++,k*=10)p.pb(k);
    p[19]=LLONG_MAX;
    int smx = p[x-1];
    int lrx = p[x]-1;
    // int smx=stoll("1"+string(x-1,'0'));
    // int lrx=stoll(string(x,'9'));
    segtre st(b.size(),0);
    int ans=0;
    // cout << p << endl;
    fon(i,n)
    {
        int sm = max(0ll,smx-a[i]);
        int lr = lrx-a[i];
        int l = lower_bound(all(b),sm)-b.begin();
        int r = upper_bound(all(b),lr)-b.begin()-1;
        int cans = st.query(l,r)*(n-i);
        ans+=cans;
        st.up(lower_bound(all(b),a[i])-b.begin(),1+i);        
    }
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
    return 0;
}