// https://www.codechef.com/START111B/problems/LCMMANIA
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin >> n;
    if((n&(n-1))==0)
    {
        cout << -1 << endl;
        return;
    }
    int p = 1;  
    while(n%(p*2)==0)
        p*=2;
    cout << p << " " << p << " " << (n-p)/2 <<endl;
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
// int lcm(int a,int b)
// {
//     return (a*b)/__gcd(a,b);
// }
    // if(n%3==0)
    // {
    //     cout << n/3 << " " << n/3 << " " << n/3 << endl;
    //     return;
    // }
    // if(n&1)
    // {
    //     cout << 1 << " " << 1 << " " << (n-1)/2 << endl;
    //     return;
    // }
    // cout << n << " : \n";
        // cout << ":" <<(n&(n-1)) << endl;
    // if(n%4==0)
    // {
    //     cout << 4 << " " << 4 << " " << (n-4)<< endl;
    //     return;
    // }
    // largest 2 ki power jo n ko divide kare
    // p/=2;  
    // cout << p << endl;
    // fo1(i,1,n,1)
    // // fo1(i,1,2,1)
    // {
    //     // fo1(p,0,30,1)
    //     fo1(j,i,n,1)
    //     {
    //         // int j = i<<p;
    //         fo1(k,j,n+1,1)
    //         {
    //             if(lcm(i,j)+lcm(j,k)+lcm(k,i)==n)
    //             {
    //                 cout << i << " " << j << " " << k << endl;
    //                 // return;
    //             }
    //         }
    //     }
    // }

    // cout << endl;
        // cout << endl;