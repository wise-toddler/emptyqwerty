// https://codeforces.com/contest/1873/problem/D
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
    int t;cin >> t;
    while(t--)
    {
        int n,k;cin >> n >> k;
        string s;cin >> s;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')
            {
                ans++;
                for(int j=i;j<min(n,i+k);j++)
                {
                    if(s[j]=='B') 
                        s[j]='W';
                }
            }
        }
        cout << ans << endl;
    }
}