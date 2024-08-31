// https://codeforces.com/group/isP4JMZTix/contest/392597/problem/O
#include <bits/stdc++.h>
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
    int n;cin>>n;
    vi a(n);
    int l=0,r=n-1;
    for(int i =0;i<n;i++)
        cin>>a[i];

    int chance=0;
    int max=0;
    int m1=0,m2=0;
    while(l<=r)
    {
        if(a[l]>a[r]) 
        {
            max =a[l];
            l++;
        }
        else
        {
            max = a[r];
            r--;
        }
        if(chance%2==0)
        {
            m1+=max;
            chance++;
        }
        else
        {
            m2+=max;
            chance++;
        }
    }
    cout<<m1<<" "<<m2<<endl;
}