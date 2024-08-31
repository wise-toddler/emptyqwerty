// https://codeforces.com/contest/1873/problem/A
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
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        if(s[0]=='a')
        {
            cout << "YES"<< endl;
        }
        else if(s[0]=='b')
        {
            cout << (s[1]=='a'? "YES" : "NO")<< endl;
        }
        else if(s[0]=='c')
        {
            cout << (s[1]=='b'? "YES" : "NO")<<  endl;
        }
    }
}