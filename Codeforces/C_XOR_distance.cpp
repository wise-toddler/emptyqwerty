// https://codeforces.com/contest/1918/problem/C
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

void solve()
{
    int a,b,r;cin>>a>>b>>r;
    if(a<b) swap(a,b);
    int ans=a-b;
    int xx = a^b;
    int c=0;
    int minn=ans;
    fo1(i,62,-1,-1)
    {
        int m1 = (1LL<<i);
        int m2 = (1LL<<(i+1));

        if((xx&(1LL<<i)) && ((c+m1)<=r) && !(b&(1LL<<i))&& (m2<=ans))
        {
            c+=m1;
            ans-=m2;
        }
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
    // int a,b,r;cin>>a>>b>>r;
    // //  to bits
    // if(a<b) swap(a,b);
    // int ans=0; // answer
    // fon(i,64)
    // {
    //     if((a&(1LL<<i)) && !(b&(1LL<<i)) && (1LL<<i)<=r && ((1LL<<(i+1))<=a))
    //     {
    //         ans+=(1LL<<i);
    //         // deb(i) deb(ans)
    //     }
    // } 
    // // __int128_t
    // // cout << bitset<64>(a) << endl;
    // // cout << bitset<64>(b) << endl;nl
    // // cout << bitset<64>(r) << endl;
    // // cout << bitset<64>(ans) << endl;
    // // cout << abs(a-b) << endl;
    // // cout << ans << endl;
    // // cout << aa << endl;
    // int ans2=ans;
    // // ans=31;
    // // r=27;
    // if(ans>r)
    // {
    //     ans2=0;
    //     bool f=0;
    //     fo1(i,63,-1,-1)
    //     {
    //         if(r&(1LL<<i) && !(ans&(1LL<<i)))
    //             f=1;
    //         if(((ans&(1LL<<i)) && (f || (r&(1LL<<i)))))
    //             ans2+=(1LL<<i);
    //     }
    // }
    // // cout << ans2 << endl;
    // // cout << bitset<18>(ans2) << endl;
    // cout << abs((a^(ans2))-(b^(ans2))) << endl;
    // // cout << abs((a^(4))-(b^(4))) << endl;
    // // cout << 