// https://atcoder.jp/contests/abc320/tasks/abc320_b
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
//longest palindrome substring
signed main()
{
    IOS
    string s;cin>>s;
    int n=s.size();
    int m=1;
    for(int i = 0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            bool flag = 0;
            if(s[i]==s[j])
            {
                flag =1;
                int l= 1+i;
                int r= j-1;
                while(l<=r)
                {
                    if(s[l]!=s[r])
                    {
                        flag = 0;
                    }
                    l++;r--;
                    if(!flag)
                        break;
                }
            }
            if(flag)
                m=max(m,j-i+1);
        }
    }
    cout << m;
}