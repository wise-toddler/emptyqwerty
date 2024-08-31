// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
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
    int n,sum;
    cin >> n >> sum;
    vi a(n);
    cin >> a[0];
    for(int i=1;i<n;i++)
        cin >> a[i];
    int ans=0;
    int st=0,en=0;
    int curr=0;
    while(en<n)
    {
        curr+=a[en];
        while(curr>sum)
        {
            curr-=a[st];
            st++;
        }
        ans=max(ans,en-st+1);
        en++;
    }
    cout << ans << endl;

}

    // a={10,100,10,10,10,10,10};
    // n=7,sum=20;
    // {
    //     // a[i]+=a[i-1];
    // } // prefix sum
    // if (a[n-1]<=sum ) // if sum of all elements is less than sum
    // {
    //     cout << n << endl;
    //     return 0;
    // }

    // while(st<=en)
    // {
    //     int mid=(st+en)/2;
    //     if(a[mid]<=sum)
    //     {
    //         ans=mid;
    //         st=mid+1;
    //     }
    //     else
    //         en=mid-1;
    // }
    // ans++;
    // // cout << ans+1 << ' ' << a[ans] << endl;
    // int c=0;
    // int eq=0;
    // st=0,en=n-1;
    // while(st<=en && (a[en]-((st>0)?a[st-1]:0)+eq) > sum)
    // {
    //     if(a[en]-a[en-1] > ((st>0)?a[st]-a[st-1]:a[st]))
    //     {
    //         en--;
    //         // c=0;
    //         // eq=0;
    //     }
    //     else if(a[en]-a[en-1] < a[st]-a[st-1])
    //     {
    //         // eq=0;
    //         st++;
    //         // c=0;
    //     }
    //     else
    //     {
    //         eq+=a[en]-a[en-1];
    //         c++;
    //         st++;
    //         en--;
    //     }
    //     if(a[en]-((st>0)?a[st-1]:0))

    //         // ans=min(ans,en-st+1+c);
    // }
    // cout << en << ' ' << st <<' ' << c <<endl;
    // if(st<=en)
    //     ans=en-st+1+c;
    // cout << ans << endl;
// 7 20
// 2 6  4  3  6  8  9
// 2 8 12 15 21 29 38