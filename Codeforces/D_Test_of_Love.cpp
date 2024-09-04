// https://codeforces.com/contest/1992/problem/D
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
bool solve()
{
    int n,m,k;cin >> n >> m >> k;
    string s;cin >> s;
    s='L'+s+'L';
    n++,n++;
    int jump_left=-1,water_need_to_swim=0,c=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='L') jump_left=m;
        else if(s[i]=='W') water_need_to_swim+=(jump_left<=0);
        else if(jump_left<=0) return 0;
        jump_left--;
    }
    return water_need_to_swim<=k;  
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();/
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
// string s;
// bool f(int id,int m,int k)
// {
//     if(id>=s.size()) return true;
//     if(s[id]=='L')
//     {
//         for(int i=1;i<=m;i++)
//         {
//             if(f(id+i,m,k)) 
//                 return true;
//         }
//     }
//     if(s[id]=='W')
//     {
//         if(k) return f(id+1,m,k-1);
//         else return false;
//     }
//     if(s[id]=='C') return false;
//     return false;
// }
// void solve()
// {
//     int n,m,k;cin >> n >> m >> k;
//     string ss;cin >> ss;
//     s='L'+ss+'L';
//     n=n+2;
//     // vvi dp(m,vi(k+1,0));
//     int dp[m][k+1];
//     memset(dp,0,sizeof(dp));
//     fon_(i,n)
//     {
//         fon(l,k+1)
//         {
//             // dp[i%m][l]=0;
//             if(i==n-1)
//             {
//                 dp[i%m][l]=1;
//                 continue;
//             }
//             if(s[i]=='L')
//             {
//                 for(int j=1;j<=m;j++)
//                 {
//                     if(i+j<n)
//                         dp[i%m][l] |= dp[(i+j)%m][l]; 
//                     else    
//                         dp[i%m][l] |= 1;
//                 }
//             }
//             if(s[i]=='W')
//             {
//                 if(l) dp[i%m][l] |= dp[(i+1)%m][l-1];
//                 else dp[i%m][l] |= 0;
//             }
//             if(s[i]=='C') dp[i%m][l]=0;
//         }
//         // memset(dp[(i+l)%m],0,sizeof(dp[(i+l)%m]));
//         // for(int j=0;j<m;j++) 
//         //     memset(dp[j],0,sizeof(dp[j]));
        
//     }
//     cout << (dp[0][k] ? "YES" : "NO") << endl;
// }