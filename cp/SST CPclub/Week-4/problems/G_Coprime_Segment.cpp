// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G
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
int gcd(int a, int b){return a%b==0?b:gcd(b,a%b);}
signed main()
{ 
    IOS
    int n;cin >> n;
    vi a(n);
    cin >> a[0];
    int g = a[0];
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        g = gcd(g,a[i]);
    }

    if(g!=1)
    {
        cout << -1 << endl;
        return 0;
    }

    int ans=n;
    int left=0;
    g=a[0];
    int rtol = 0;
    for(int i=0;i<n;i++)
    {
        g = gcd(g,a[i]);
        if(g==1)
        {
            g=a[i];       
            rtol = i;

            while (gcd(g, a[rtol])!= 1)
            {   
                g = gcd(g,a[rtol]);
                rtol--;
            }
            left = rtol;
            ans = min(ans,i-left+1);
            g=a[i];
        }
    }
    cout << ans << endl;
}
// 