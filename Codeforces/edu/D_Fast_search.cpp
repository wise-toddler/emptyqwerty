// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
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
int binSear(vi &a,int x)
{
    int st=0,en=a.size()-1;
    int ans=-1;
    while(st<=en)
    {
        int mid = (st+en)/2;
        if(a[mid]<=x)
        {
            ans=mid;
            st=mid+1;
        }
        else 
            en=mid-1;
    }
    return ans;
}
signed main()
{
    IOS
    int n;cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int q;cin>>q;
    sort(all(a));
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout<<binSear(a,r)-binSear(a,l-1)<<' ';
    }
}