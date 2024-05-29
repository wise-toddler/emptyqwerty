// https://codeforces.com/problemset/problem/1714/E
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
bool ch(vi &a , bool z) // z = 0 for 1z and 1 for 3z
{
    int c=0;
    for(auto x : a)
    {
        int ld = x%10;
        int td = ((x/10)%10)&1;
        if(ld&1)
        {
            td = td^((2*ld)>9);
            ld = (ld*2)%10;
        }
        if(ld==0) return 0;
        if(td^(ld==6)) c++;
    }
    return c==(z?a.size():0);
}
bool ch5(vi &a)
{
    set<int> s;
    for(auto x : a)
    {
        if(x%5) return 0;
        int td = (x/10)%10;
        int ld = x%10;  
        if(ld==0) s.insert(x/10);
        else if(ld==5) s.insert(x/10+1);
    }
    return s.size()==1;
}
bool solve()
{
    int n; cin >> n;
    vi a(n); cin >> a;
    bool f1 = ch5(a) || ch(a,0) || ch(a,1);
    return f1;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"Yes":"No") << endl;
    }
}