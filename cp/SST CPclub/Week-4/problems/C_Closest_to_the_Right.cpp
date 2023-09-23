// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
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
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    for(int i=0;i<k;i++)
    {
        int x;cin>>x;
        int st=0,en=n-1;
        int ans=n;
        while(st<=en)
        {
            int mid = (st+en)/2;
            if(a[mid]>=x)
            {
                ans=mid;
                en=mid-1;
            }
            else 
                st=mid+1;
        }
        cout<<ans+1<<endl;
    }
}