// https://codeforces.com/contest/1881/problem/A
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
bool issubstr(string a,string b)
{
    int n=a.size(),m=b.size();
    for(int i=0;i<n-m+1;i++)
    {
        if(a.substr(i,m)==b)
            return true;
    }
    return false;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n,m;cin >> n >> m;
        string x,s;cin >> x >> s;
        int o=0;
        while(x.size()<s.size())
        {
            x+=x;
            o++;
        }
        if(issubstr(x,s))
        {
            cout << o << endl;
            continue;
        }
        x+=x;
        o++;
        if(issubstr(x,s))
        {
            cout << o << endl;
            continue;
        }
        cout << -1 << endl;

        
    }
}