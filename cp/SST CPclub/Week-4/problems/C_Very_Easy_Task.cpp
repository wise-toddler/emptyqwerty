// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
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
    int n,x,y;cin >> n >> x >> y;
    n-=1;
    int st = 0;
    int en = 1e10;
    int ans = 0;
    while(st<=en)
    {
        int mid = st+(en-st)/2;
        if((mid/x)+(mid/y)>=n)
        {
            ans = mid;
            en = mid-1;
        }
        else
            st = mid+1;
    }
    cout << (ans + min(x,y))<< endl;
    // cout << (((n-1)*x*y)/(x+y))+min(x,y)<<endl;
}
