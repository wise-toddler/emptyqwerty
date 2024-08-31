// https://codeforces.com/contest/1991/problem/F
#include <bits/stdc++.h>
#include <list>
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

bool solve(vi &a)
{
    int n=a.size();
    fo1(i,5,n,1) // 0 1 2 3 4 5 6
    {
        vi aa = {a[i-5],a[i-4],a[i-3],a[i-2],a[i-1],a[i]};
        if(aa[0]+aa[1]>aa[2] and aa[3]+aa[4]>aa[5]) return true;
        if(aa[0]+aa[1]>aa[3] and aa[2]+aa[4]>aa[5]) return true;
        if(aa[0]+aa[1]>aa[4] and aa[2]+aa[3]>aa[5]) return true;
        if(aa[0]+aa[1]>aa[5] and aa[2]+aa[3]>aa[4]) return true;

        if(aa[0]+aa[2]>aa[3] and aa[1]+aa[4]>aa[5]) return true;
        if(aa[0]+aa[2]>aa[4] and aa[1]+aa[3]>aa[5]) return true;
        if(aa[0]+aa[2]>aa[5] and aa[1]+aa[3]>aa[4]) return true;

        if(aa[0]+aa[3]>aa[4] and aa[1]+aa[2]>aa[5]) return true;
        if(aa[0]+aa[3]>aa[5] and aa[1]+aa[2]>aa[4]) return true;

        if(aa[0]+aa[4]>aa[5] and aa[1]+aa[2]>aa[3]) return true;
    }
    return false;
}

void solve()
{
    int n,q;cin >> n >> q;
    vi a(n);cin >> a;
    while(q--)
    {
        int l,r;cin >> l >> r;
        l--,r--;
        int n=r-l+1;
        if(n>=50) 
        {
            cout << "YES" << endl;
            continue;
        }
        vi aa;
        // 2 2 10 4 10 6 1
        // 1 2 2 4 6 10 10
        fo1(i,l,r+1,1) aa.pb(a[i]); 
        sort(all(aa));
        vi s;
        fon(i,aa.size()-2) if(aa[i]+aa[i+1]>aa[i+2]) s.pb(i);
        if(s.size()==0)
        {
            cout << "NO" << endl;
            continue;
        }
        // deb(s);
        if(s.back()>=s[0]+3)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << (solve(aa) ? "YES" : "NO") << endl;
    }
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}