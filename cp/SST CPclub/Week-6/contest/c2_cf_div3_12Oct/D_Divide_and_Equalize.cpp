// https://codeforces.com/contest/1881/problem/D
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
        int n;cin >> n;
        vi a(n);
        for(int &i:a)cin >> i;
        map<int,int> mp; 
        for(int &i:a)
        {
            mp[1]++;
            int x=i;
            for(int j=2;j*j<=x;j++)
            {
                while(x%j==0)
                {
                    mp[j]++;
                    x/=j;
                }
            }
            if(x>1)
                mp[x]++;
        }
        for(auto i:mp)
        {
            if(i.second%n!=0)
            {
                cout << "NO" << endl;
                goto end;
            }
        }
        cout << "YES" << endl;
        end:;
    }
}