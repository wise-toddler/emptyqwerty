// https://cses.fi/problemset/task/1661
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
signed main()
{
    IOS
    int n,x;cin >> n >> x;
    vi a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int sum = 0;
    int ans = 0;
    map<int,int> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        ans += mp[sum-x];
        mp[sum]++;
    }
    cout << ans << endl;
}