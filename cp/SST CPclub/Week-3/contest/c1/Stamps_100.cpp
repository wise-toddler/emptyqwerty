// https://www.codechef.com/problems/S100
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
        int n;cin>>n;
        string s;cin>>s;
        int flag=-1;
        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='1')
            {
                flag=i;
                break;
            }
        }
        for(int i = 0; i < n-2; i++)
        {
            if(i==flag)
                cout<<'1';
            else
                cout<<'0';
        }
        if(flag==-1)
            cout<<s[n-2]<<s[n-1]<<endl;
        else
            cout<<"00"<<endl; 

    }
}

// 1101001
// 1000000
// 