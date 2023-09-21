// https://codeforces.com/contest/1873/problem/G
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
bool contains(string s,string t)
{
    int n = s.size();
    int m = t.size();
    for(int i=0;i<n-m+1;i++)
    {
        if(s.substr(i,m)==t) return true;
    }
    return false;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        string s;cin >> s;
        string s1= s;
        int n = s.size();
        int ans = 0;
        while(contains(s,"AB") || contains(s,"BA"))
        {   
            while(contains(s,"AB"))
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if(s[i]=='A' && s[i+1]=='B')
                    {
                        s[i]='B';
                        s[i+1]='C';
                        ans++;
                    }
                }
            }
            while(contains(s,"BA"))
            {
                for(int i=0;i<n-1;i++)
                {
                    if(s[i]=='B' && s[i+1]=='A')
                    {
                        s[i]='C';
                        s[i+1]='B';
                        ans++;
                    }
                }
            }
        }
        int ans1=0;
        while (contains(s1, "AB") || contains(s1, "BA"))
        {
            while (contains(s1, "BA"))
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (s1[i] == 'B' && s1[i + 1] == 'A')
                    {
                        s1[i] = 'C';
                        s1[i + 1] = 'B';
                        ans1++;
                    }
                }
            }
            while (contains(s1, "AB"))
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (s1[i] == 'A' && s1[i + 1] == 'B')
                    {
                        s1[i] = 'B';
                        s1[i + 1] = 'C';
                        ans1++;
                    }
                }
            }
        }

        cout << (ans1>ans ? ans1:ans) << endl;
    }
}
// ABAA
// ACBA
