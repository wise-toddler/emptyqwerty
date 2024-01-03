// https://codeforces.com/contest/1914/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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
int dp[100005][2][2][2];

int f(int id,bool A,bool B,bool C,vi &a,vi &b,vi &c)
{

    if(id==a.size())
        return 0;

    if(A&&B&&C) return 0;
    
    if(dp[id][A][B][C]!=-1) 
        return dp[id][A][B][C];
    
    int ans=f(id+1,A,B,C,a,b,c);
    
    if(A==0) ans=max(ans,f(id+1,1,B,C,a,b,c)+a[id]);
    if(B==0) ans=max(ans,f(id+1,A,1,C,a,b,c)+b[id]);
    if(C==0) ans=max(ans,f(id+1,A,B,1,a,b,c)+c[id]);
    return dp[id][A][B][C]=ans;
}

void solve()
{
    int n;cin>>n;
    vi a(n),b(n),c(n); cin>>a>>b>>c;
    // memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    dp[i][j][k][l]=-1;
        
    cout << f(0,0,0,0,a,b,c) << endl;
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