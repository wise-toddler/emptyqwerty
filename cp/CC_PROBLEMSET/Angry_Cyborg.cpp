// https://www.codechef.com/BYTR20B/problems/AGCY
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
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        //cout << i << ' ';
        print(v[i]);
    }
}
void solve()
{
    int n,q;cin >> n >> q;
    vi v(n); // 0 0 0 0 0 
    vii Q(q,vi(2,0)); // 3
    fo1(i,0,q,1)
    {
        int l,r;cin >> l >> r;
        l--;r--;
        Q[i][0]=l;
        Q[i][1]=r;
        v[l]+=1;
        if(r!=n-1)
            v[r+1]-=1;
    }
    print(v); 
    
    fo1(i,1,n,1)
        v[i]+=v[i-1];
    print(v);
    
    fo1(i,0,q,1)
        if(v[Q[i][1]]!=n-1)
            v[Q[i][1]+1]-=Q[i][1]-Q[i][0]+1;
    print(v);
    fo1(i,1,n,1)
        v[i]+=v[i-1];
    print(v);

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