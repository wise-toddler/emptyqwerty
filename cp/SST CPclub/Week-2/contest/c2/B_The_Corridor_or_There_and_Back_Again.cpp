// https://codeforces.com/contest/1872/problem/B
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
    int t;
    cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int min=INT_MAX;
        while(n--)
        {
            int d,s;cin >> d >> s;
            int last = d+(s+1)/2-1;
            if(last<min)
                min=last;
        }
        cout << min << endl;
    }
}