// https://vjudge.net/problem/Kattis-landscape
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
vi ans,ty1,ty2;
vector <pii> ty; // first term and common difference
void solve()
{
    char c;cin >> c;
    int l,r;cin >> l >> r;
    if(c=='R')
    {
        ty1[l-1]+=1; 
        if(r<ans.size())
            ty1[r]-=1;
    }
    if(c=='D')
    {
        ty1[l-1]-=1;
        if(r<ans.size())
            ty1[r]+=1;
    }
    if(c=='H')
    {
        ty2[l-1]+=1;
        ty2[(l+r)/2]-=1;
        
        if(r<ans.size())
            ty2[r]-=1;   
    }
    if(c=='V')
    {
        ty2[l-1]-=1;
        if(r<ans.size())
            ty2[r]+=1;
    }
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    int n;cin >> n >> t;
    // cin >> t;
    ans.resize(n);
    ty1.resize(n);
    ty2.resize(n);
    ty.resize(n,pii(0,0));
    while(t--)
    {
        solve();
    }
    int sum1=0,sum2=0;
    fo1(i,1,n,1)
    {
        ty1[i]+=ty1[i-1];
    }

}