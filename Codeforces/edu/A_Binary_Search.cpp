// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
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
    int n,f;cin>>n>>f;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<f;i++)
    {
        int x;cin>>x;
    
        int st= 0, en = n-1;
        while(st<=en)
        {
            int mid = (st+en)/2;
            if(a[mid]==x)
            {
                cout << "YES" << endl;
                goto here;
            }
            else if(a[mid]<x)
                st=mid+1;
            else 
                en = mid-1;
        }
        cout << "NO" << endl;
        here:;
    }
}