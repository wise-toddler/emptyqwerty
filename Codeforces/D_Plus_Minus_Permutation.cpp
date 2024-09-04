// https://codeforces.com/contest/1872/problem/D
// Date: 2021/08/14
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

int f(int n){return (n*(n+1))/2;}
int lcm(int a,int b){return a*b/gcd(a,b);}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}

signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n,x,y;cin >> n >> x >> y;
        int xn = n-n/x+n/lcm(x,y), yn = n/y-n/lcm(x,y);
        int xx = f(n)-f(xn);
        int yy = f(yn);
        cout << xx-yy << endl;
    }
}