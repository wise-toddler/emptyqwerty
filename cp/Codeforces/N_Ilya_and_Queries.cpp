// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md
// https://codeforces.com/group/isP4JMZTix/contest/386415/problem/N
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
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
    string s;cin >> s;
    int n= s.size();
    vi v(n);
    v[0]=0;
    int count=0;
    for( int i = 1; i < n; i++ )
    {
        if(s[i-1]==s[i])
            count++;
        v[i]=count;
    }
    int t;cin>>t;
    while(t--)
    {
        int l,r;cin >> l >>r;
        l--;r--;
        cout << v[r]-v[l] << endl;
    }
}