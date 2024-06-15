// https://codeforces.com/contest/1980/problem/D
#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
bool solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    vi b;
    fo1(i,1,n,1)
    {
        b.pb(__gcd(a[i-1],a[i]));
    }
    // deb(b)
    // premax , sufmax , premin , sufmin of b 
    vi premax(n-1),sufmax(n-1),premin(n-1),sufmin(n-1);
    premax[0]=b[0];
    premin[0]=b[0];
    sufmax[n-2]=b[n-2];
    sufmin[n-2]=b[n-2];
    fo1(i,1,n-1,1)
    {
        premax[i]=max(premax[i-1],b[i]);
        premin[i]=min(premin[i-1],b[i]);
    }
    fon_(i,n-2)
    {
        sufmax[i]=max(sufmax[i+1],b[i]);
        sufmin[i]=min(sufmin[i+1],b[i]);
    }
    // deb(premax)deb(sufmax)deb(premin)deb(sufmin) nl nl
    // return 1;
    // check non decreasing
    auto ch = [&](vi p)-> vi
    {
        vector<int> pos;
        int cnt_dips=0;
        int prev=p[0];
        fo1(i,1,p.size(),1)
        {
            if(p[i]<prev) {cnt_dips++;pos.pb(i);}
            prev=p[i];
        }
        return pos;
    };
    vi pos = ch(b);
    int dip = pos.size();
    // deb(dip)
    if(dip==0) return 1;
    if(dip>2) return 0;
    // if(dip==2) if(abs(pos[0]-pos[1])>1) return 0;
    // deb(a)
    // deb(b)
    // deb(pos)
    int x=pos[0];
    // for(auto x : pos)
    {
        // try to remove x-1,x,x+1
        // c1
        int tr=x-1;
        if(tr==0) 
        {
            vi y(b.begin()+1,b.end());
            if(ch(y).size()==0) return 1;
        }
        if(0<=(tr-1) && (tr+1)<n)
        {
            int t1=b[tr-1],t2=b[tr];
            int num = gcd(a[tr-1],a[tr+1]);
            b[tr-1]=b[tr]=num;
            if(ch(b).size()==0) return 1;
            b[tr-1]=t1;b[tr]=t2; 
        }
        tr=x;
        if(0<=(tr-1) && (tr+1)<n)
        {
            int t1=b[tr-1],t2=b[tr];
            int num = gcd(a[tr-1],a[tr+1]);
            b[tr-1]=b[tr]=num;
            if(ch(b).size()==0) return 1;
            b[tr-1]=t1;b[tr]=t2; 
        }
        tr=x+1;
        if(x+1==n-1) 
        {
            // cout << "mlc" << endl;
            vi y(b.begin(),b.end()-1);
            if(ch(y).size()==0) return 1;
        }
        if(0<=(tr-1) && (tr+1)<n)
        {
            int t1=b[tr-1],t2=b[tr];
            int num = gcd(a[tr-1],a[tr+1]);
            b[tr-1]=b[tr]=num;
            if(ch(b).size()==0) return 1;
            b[tr-1]=t1;b[tr]=t2; 
        }
        // c2 -> in a 
    }
        // cout << "YESssssssssss" << endl;
    return 0;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}