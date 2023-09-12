// https://atcoder.jp/contests/abc319/tasks/abc319_a
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
    string s[] =  {"tourist","ksun48","Benq","Um_nik","apiad","Stonefeang","ecnerwala","mnbvmar","newbiedmy","semiexp"};
    int n[] = {3858,3679,3658,3648,3638,3630,3613,3555,3516,3481};
    string a;cin>>a;
    for (int i = 0; i < 10; i++)
    {
        if (s[i]==a)
        {
            cout<<n[i]<<endl;
            return 0;
        }
    }
}