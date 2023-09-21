// https://codeforces.com/contest/1873/problem/B
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
        int n;cin >> n;
        vi a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(all(a));
        int ans=a[0]+1;
        for(int i=1;i<n;i++)
        {
            ans*=a[i];
        }
        cout << ans << endl;
    }
}