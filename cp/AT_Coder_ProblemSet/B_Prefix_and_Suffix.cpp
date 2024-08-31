// https://atcoder.jp/contests/abc322/tasks/abc322_b
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
    string s,t;cin>>s>>t;
    int c=0;
    if(s[0]==t[0])
    {
        for(int i=0;i<n;i++)
            if(s[i]==t[i])
                c++;
    }
    int d=0;
    if(s[n-1]==t[m-1])
    {
        for(int i=0;i<n;i++)
            if(s[n-i-1]==t[m-i-1])
                d++;
    }
    if(c==n && d==n)
    {
        cout << 0 << endl;
        return 0;
    }
    if(c==n)
    {
        cout << 1 << endl;
        return 0;
    }
    if(d==n)
    {
        cout << 2 << endl;
        return 0;
    }
    cout << 3 << endl;
}