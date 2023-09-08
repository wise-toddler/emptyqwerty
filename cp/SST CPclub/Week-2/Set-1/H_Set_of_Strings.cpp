// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md
// https://codeforces.com/group/isP4JMZTix/contest/380288/problem/H
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
    int k;cin >> k;
    string s;cin >> s;
    // vector<char> v;
    // for(int i=0;i<k;i++)
    //     cin >> v[i];
    set<char> set;
    for(int i=0;i<s.size();i++)
    {
        set.insert(s[i]);
    }
    if(set.size()>=k)
    {
        cout << "YES" << endl;
        set.clear();
        set.insert(s[0]);
        for (int i = 0; i < s.size(); i++)
        {
            cout << s[i];
            // if (k > 1 && set.find(s[i+1])==set.end())//runtime 15ms
            if (k > 1 && s[i+1]!=s[i] && set.find(s[i+1])==set.end())//runtime 0ms
            {
                k--;
                cout << endl;
                set.insert(s[i+1]);
            }
        }
    }
    else
        cout << "NO" << endl;
    //print set
    // for(auto it=set.begin();it!=set.end();it++)
    //     cout << *it << " ";



}