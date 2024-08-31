// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/C
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
    int n,s;cin>>n>>s;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans =0;
    int x=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        x+=a[i];
        while(x>s && j<n)
        {
            ans+=(n-i);
            x-=a[j];
            j++;
            // if(x>=s)
        }
    }
    // cout<<ans<<endl;
    cout<<((n+1)*n)/2-ans<<endl;
}
// s= 20
// 2 6 4 3 6 8 9
/*
    i=0
        x=2
        j=0 // 2
        ans = 0
    i=1
        x=8
        j=0 // 2
        ans = 0
    i=2
        x=12
        j=0 // 2
        ans = 0
    i=3
        x=15
        j=0 // 2
        ans = 0
    i=4
        x=21
        j=0 // 2
        ans = 3
    i=5
        x=29
        j=0 // 2
        x=27
        j=1 // 6
        x=21
        j=2 // 4
        ans = 3+2
    i=6
        x=29
        j=2 // 4
        x=25
        j=3 // 3
        x=22
        j=4 // 6
        ans = 6

        

*/
