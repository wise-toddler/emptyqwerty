// https://codeforces.com/contest/1873/problem/C
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
        int sum = 0;
        for(int i = 1; i <=10; i++)
        {
            string s;cin >> s;
            // cout << s << endl;
            for(int j = 1; j <=10; j++)
            {
                if(s[j-1]=='X') 
                {
                    int x = min(j,10-j+1);
                    int y = min(i,10-i+1);
                    sum+=min(x,y);
                }
            }
        }
        cout << sum << endl;
        // return 0;
    }
}