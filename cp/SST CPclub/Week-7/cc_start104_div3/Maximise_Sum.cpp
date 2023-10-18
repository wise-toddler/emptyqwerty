// https://www.codechef.com/problems/MAXIMISESUM
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
#define debug(x) cout << #x << ": " << x << endl;
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vi a(n);
        int sum = 0;
        for(int &i : a) 
        {
            cin >> i;
            sum += i;
        }
        vi b(n);
        b[0] = a[0];
        for(int i=1;i<n;i++)
        {
            b[i] = max(b[i-1],a[i]);
        }
        vi c(n);
        c[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            c[i] = max(c[i+1],a[i]);
        }
        vi d(n);
        for(int i=0;i<n;i++)
        {
            d[i] = min(b[i],c[i]);
        }
        int sum2 = 0;
        for(int i=0;i<n;i++)
        {
            sum2 += d[i];
        }
        cout << sum2 << endl;
        // int l = -1;
        // for(int i=0;i<n-1;i++)
        // {
        //     if(a[i]>a[i+1]) 
        //     {
        //         l = i;
        //         break;
        //     }
        // }
        // int r = -1;
        // for(int i=n-1;i>0;i--)
        // {
        //     if(a[i]>a[i-1]) 
        //     {
        //         r = i;
        //         break;
        //     }
        // }
        // debug(l)
        // debug(r)
        // if(l==-1 || r==-1)
        // {
        //     cout << sum << endl;
        //     continue;
        // }
        // for(int i=l+1;i<r;i++)
        // {
        //     sum -= a[i];
        // }
        // debug(sum)
        // stack<int> maxr;
        // for(int i=r;i>=0;i--)
        // {
        //     if(maxr.empty()||a[i]>maxr.top()) 
        //         maxr.push(i);
        // }
        // for (int i = l; i <=r; i++)
        // {
        //     while(maxr.size() && maxr.top()<=i) 
        //     {
        //         maxr.pop();
        //     }
        //     while(!maxr.empty() && a[maxr.top()]>a[i])
        //     {
        //         maxr.pop();
        //     }
        // }
    }
}