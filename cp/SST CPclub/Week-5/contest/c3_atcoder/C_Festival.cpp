// https://atcoder.jp/contests/abc322/tasks/abc322_c
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
signed main()
{
    IOS
    int n,m;cin>>n>>m;
    vi a(m+2);
    a[0]=0;
    for(int i=1;i<=m;i++) cin>>a[i];
    a[m+1]=n+1;
    for(int i=0;i<m;i++)
    {
        int d = a[i+1]-a[i]-1;
        while(d>=0)
        {
            cout << d << endl;
            d--;
        }
    }


}