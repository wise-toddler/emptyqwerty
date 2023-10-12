// https://codeforces.com/contest/1881/problem/C
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define v vector
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        v <v<char>> a(n,v<char>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        int op = 0;

        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int p1 = a[i][j]; // 0 1
                int p2 = a[j][n-i-1]; // 1 2
                int p3 = a[n-i-1][n-j-1]; // 2 3
                int p4 = a[n-j-1][i]; // 3 0
                int maxa = max({p1,p2,p3,p4});
                op += maxa-p1;
                op += maxa-p2;
                op += maxa-p3;
                op += maxa-p4;
                

            }
        }
        cout << op << endl;
                
    }
}