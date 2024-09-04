// https://codeforces.com/problemset/problem/545/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ff first
#define ss second
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
void solve()
{
    int n;cin >> n;
    v<pii> a(n+2);    
    a[0] = {-1e18,0};
    for(int i=1;i<=n;i++) cin >> a[i].ff >> a[i].ss;
    // for(int i=1;i<=n;i++) cout << i << " " << a[i].ff << " " << a[i].ss << endl;
    a[n+1] = {1e18,0};
    int c=0;
    int r=-1e18;
    fo1(i,1,n+1,1)
    {
        if(a[i].ff - a[i].ss > max(r,a[i-1].ff)) c++,r = a[i].ff;
        else if(a[i].ff + a[i].ss < a[i+1].ff) c++,r=a[i].ff + a[i].ss;
        // cout << i << " ";deb(c)     
    }
    cout << c;   
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
/*
1 : 1 7
2 : 3 11
3 : 6 12
4 : 7 6
5 : 8 5
6 : 9 11
7 : 15 3
8 : 16 10
9 : 22 2
10 :  23 3
11 :  25 7
12 :  27 3
13 :  34 5
14 :  35 10
15 :  37 3
16 :  39 4
17 :  40 5
18 :  41 1
19 :  44 1
20 :  47 7
21 :  48 11
22 :  50 6
23 :  52 5
24 :  57 2
25 :  58 7
26 :  60 4
27 :  62 1
28 :  67 3
29 :  68 12
30 :  69 8
31 :  70 1
32 :  71 5
33 :  72 5
34 :  73 6
35 :  74 4
*/
// if(r==1)
// {
//     if(a[i].ff + a[i].ss < a[i+1].ff)
//     {
//         r=1;
//         c++;
//     }
//     else r=0;
// }
// else c++;