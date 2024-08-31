// https://codeforces.com/contest/1872/problem/C
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
    int t;cin >> t;
    while(t--)
    {
        int l,r;cin >> l >> r;
        if(r<4)
        {
            cout << -1 << endl;
            continue;
        }
        if(l<4)
            l=4;
        if(l==r && l%2!=0)
        {
            for(int i=2;i*i<=l;i++)
            {
                if(l%i==0)
                {
                    cout << l/i << " " << l-l/i << endl;
                    goto here;       
                }
            }
            cout <<-1 << endl;
            here:;
        }
        else 
            cout << (l+1)/2 << " " << (l+1)/2 << endl;
    }
}