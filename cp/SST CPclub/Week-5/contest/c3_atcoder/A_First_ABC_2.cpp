// https://atcoder.jp/contests/abc322/tasks/abc322_a
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
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n-2;i++)
    {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}