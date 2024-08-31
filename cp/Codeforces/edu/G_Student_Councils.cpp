// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/G
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
int k;
vi a;
bool check(int mid)
{
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        cnt+=min(a[i],mid);
    }
    return cnt/mid>=k;
}
signed main()
{
    IOS
    cin>>k;
    int n;cin>>n;
    a.resize(n);
    int sum=0;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    // sort(all(a));
    int st=1,en=sum/k;
    int ans=0;
    while(st<=en)
    {
        int mid = st+(en-st)/2;
        if(check(mid))
        {
            ans = mid;
            st = mid+1;
        }
        else
            en = mid-1;
    }
    cout << ans << endl;
}