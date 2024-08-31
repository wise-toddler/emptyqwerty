// https://codeforces.com/contest/1878/problem/A
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
        int n,k;cin >> n >> k;
        vi a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[a[i]]++;
        
        if(mp[k]!=0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}