// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md
// https://codeforces.com/group/isP4JMZTix/contest/380288/problem/N
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
signed main()
{
    IOS
    int n; cin >> n;
    string s1,s2;cin >> s1 >> s2;
    vi v1(26);
    vi v2(26);
    for(int i=0;i<n;i++)
    {
        v1[s1[i]-'a']++;
        v2[s2[i]-'a']++;
    }
    int c=0;
    for(int i = 0;i<26;i++)
    {
        if(v1[i]!=v2[i])
            c+=abs(v1[i]-v2[i]);
    }
    cout << c/2 << endl;
    
}