// https://codeforces.com/contest/918/problem/B
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
    int n,m;cin >> n >> m;

    map<string,string> mp;
    for(int i=0;i<n;i++)
    {
        string s1,s2;cin >> s1 >> s2;
        mp[s2] = s1;
    }
    for(int i=0;i<m;i++)
    {
        string s1,s2;cin >> s1 >> s2;
        cout << s1 << ' ' << s2 <<" #";
        s2.pop_back();
        cout << mp[s2] << endl; 
    }
}
