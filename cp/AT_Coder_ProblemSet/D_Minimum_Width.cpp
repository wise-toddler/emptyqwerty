// https://atcoder.jp/contests/abc319/tasks/abc319_d
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

bool fit(vi a,int w,int maxlines)
{
    int filled=0;
    int limit=1;
    for(int i =0;i<a.size();i++)
    {
        if(a[i]>w)
            return false;
        if(filled + a[i] <= w)
        {
            filled+=a[i]+1;
        }
        else
        {
            limit++;filled = a[i]+1;
        }        
    }
    return limit<=maxlines;
}

int binSear(vi a,int lines,int max)
{
    int st=0,en=max,ans=-1;
    while(st<=en)
    {
        int mid=st+(en-st)/2;
        if(fit(a,mid,lines))
        {
            ans = mid;
            en=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    return ans;
}

// void print(vi v)
// {
//     for(int i=0;i<v.size();i++)
//         cout << v[i] << ' ';
//     cout << endl;
// }
// void print(vii v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         // cout << i << ' ';
//         print(v[i]);
//     }
// }

signed main()
{
    IOS
    int n,lines;
    cin >>n>>lines;
    // n=13;
    // w=3;
    vi a;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;cin >>x;
        a.pb(x);
        sum+=x;
    }
    // cout <<sum+n-1<<endl<<endl;
    cout<< binSear(a,lines,sum+n-1);

}