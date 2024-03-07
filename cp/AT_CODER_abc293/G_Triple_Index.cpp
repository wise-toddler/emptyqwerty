// https://atcoder.jp/contests/abc293/tasks/abc293_g
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << '\n';return os;}
template<typename T>ostream& operator<<(ostream& os, v<v<T>>& v){for(auto& x : v)os << x << endl;return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
struct Q
{
    int l,r,id;
};
int S=500;
bool cmp(Q a,Q b)
{
    if(a.l/S!=b.l/S)return a.l<b.l;
    return a.r<b.r;
}
int ans=0;
int nc3(int x)
{
    return (x*(x-1)*(x-2))/6;
}
int fr[1000001];
void add(int idx)
{   
    ans-=nc3(fr[idx]);
    fr[idx]++;
    ans+=nc3(fr[idx]);
}
void remove(int idx)
{
    ans-=nc3(fr[idx]);
    fr[idx]--;
    ans+=nc3(fr[idx]);
}
void solve()
{
    int n,q;cin >> n >> q;
    vi a(n);cin >> a;
    v<Q> queries(q);
    fon(i,q)
    {
        int l,r;cin >> l >> r;
        l--,r--;
        queries[i] = {l,r,i};
    }
    sort(all(queries),cmp);
    vi res(q);
    int l=0,r=-1;
    for(auto i : queries)
    {
        while(r<i.r)add(a[++r]);
        while(l>i.l)add(a[--l]);
        while(r>i.r)remove(a[r--]);
        while(l<i.l)remove(a[l++]);
        res[i.id] = ans;
    }
    cout << res;
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