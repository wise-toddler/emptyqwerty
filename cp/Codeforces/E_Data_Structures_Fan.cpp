// https://codeforces.com/contest/1872/problem/E
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
        int n;cin >> n;
        vi a(n);
        for(int i=0;i<n;i++)cin >> a[i];
        string s;cin >> s;
        int q;cin >> q;
        while(q--)
        {
            int tp;cin >> tp;
            if(tp==1)
            {
                int l,r;cin >> l >> r;
                l--,r--;
                for (int i = l; i <= r; i++)
                    s[i]^=1;
                
            }
            else
            {
                int g;cin >> g;
                int forfirst = 0;
                int num=3;
                for(int i=0;i<n;i++)
                {
                    bool f = (((int)s[i])-48)==g;
                    // cout << s[i] << " "<< g <<" "<<s[i]==g<< endl;
                    // cout << (int)s[i]-48 << " "<< g <<" "<< f << endl;
                    if(f)
                    {
                        if(forfirst==0)
                        {
                            forfirst++;
                            num=a[i];
                        }
                        else
                        {
                            num^=a[i];
                        }
                    }
                } 
                forfirst==0 ? cout << 0 << " ": cout << num <<" ";
                // cout << num << endl;
                // cout << endl;
            }
        }
        cout << endl;
    }
/*
12345
10101


*/