// https://cses.fi/problemset/task/1662
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
        cout << i << ' ';
        print(v[i]);
    }
}
signed main()
{
    IOS
    int n;cin >> n;
    vi a;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        int x;cin >> x;
        sum += x;
        sum=(sum%n+n)%n;
        a.pb(sum);
    }
    map<int,int> mp;
    mp[0] = 1;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += mp[a[i]];
        mp[a[i]]++;
    }
    cout << ans << endl;
}