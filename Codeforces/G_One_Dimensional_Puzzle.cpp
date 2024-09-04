// https://codeforces.com/contest/1931/problem/G
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
int m = 998244353;
vvi adj = {{1,2},{0,3},{1,2},{0,3}};

int rec(vi &a,int id,int sum)
{
    if(sum==0)return 1;
    int ans = 0;
    for(auto x : adj[id])
    {
        if(a[x]==0)continue;
        a[x]--;
        if(rec(a,x,sum-1)) ans = (ans + 1)%m;
        a[x]++;
    }
    return ans;
}
// optimise the rec function
// int rec_opt(vi &a,int id,int sum)
// {
//     if(sum==0)return 1;
//     for(auto x : adj[id])
//     {
//         if(a[x]==0)continue;
//         a[x]--;
//         if(rec(a,x,sum-1))return 1;
//         a[x]++;
//     }
//     return 0;
// }
void solve()
{
    vi a(4);cin >> a;
    int sum = accumulate(all(a),0LL);
    // all 0 then 1
    // a0 a1 a2 a3
    // it 3 nums are 0
    // then if a0 or a1 non 0 then 0 but if a2 or a3 non 0 then 1
    // if 2 nums are 0
    // then if a0 and a1 non 0 then a0==a1?1:0 but if a2 and a3 non 0 then 0
    // if (a0 and a2) or (a1 and a3) non 0 then a0==1 or a1==1?1:0
    // else 0 in all other cases
    int ans = 0;
    cout << a<<endl;
    fon(i,4)
    {
        if(a[i]==0)continue;
        a[i]--;
        ans = (ans + rec(a,i,sum-1))%m;
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
}