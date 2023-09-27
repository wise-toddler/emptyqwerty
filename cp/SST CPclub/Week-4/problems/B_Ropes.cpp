// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
int n,k;
vi a;
bool check(double mid)
{
    int cnt = 0;
    for(int i=0;i<n;i++)
        cnt += a[i]/mid;
    return cnt>=k;
}
signed main()
{
    IOS
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    double ans = 0.0;
    double st = 0;
    double en = 1e9;
    // while(st<=en)
    for(int i =0;i<100;i++)
    {
        double mid = st+(en-st)/2; 
        if(check(mid))
        {
            // ans = mid; 
            // st = mid+1e-7;
            st = mid;
        }
        else
            en = mid;
            // en = mid-1e-7;
    }
    // cout << fixed << setprecision(6) << ans << endl;
    cout << setprecision(20)<< st << endl;
}