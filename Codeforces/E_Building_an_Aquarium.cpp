// https: // codeforces.com/contest/1873/problem/E
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
int canHold(int h,vi a)
{
    int n = a.size();
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += max(0LL,h-a[i]);
    }
    return sum;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n,w;cin >> n >> w;
        // int w = 0;
        vi a(n);
        int minz =INT32_MAX;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            minz = min(minz,a[i]);
        }
        // cout <<"d "<< minz << ' ' << w<< endl;
        int st = 0, en = minz+w;
        int ans=-1;
        while(st<=en)
        {
            int mid = (st+en)/2;
            // cout <<"d "<< mid << ' ' << canHold(mid,a) << endl;
            if(canHold(mid,a)<=w)
            {
                ans = mid;
                st = mid+1;
            }
            else
            {
                en = mid-1;
            }
        }
        cout<<ans<<endl;
    }
}