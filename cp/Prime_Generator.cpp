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

bool isPrime(int n)
{
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    if(n%2==0 || n%3==0)
        return false;
    for (int i = 5; i*i <= n; i=i+6)
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int m,n;cin >> m >> n;
        for (int  i = m; i <= n; i++)
        {
            if(isPrime(i))
                cout << i << endl;
        }
        cout << endl;   
    }
}