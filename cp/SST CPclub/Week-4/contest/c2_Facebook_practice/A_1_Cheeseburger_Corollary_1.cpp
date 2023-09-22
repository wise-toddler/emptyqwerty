// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/A1?source=facebook
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
    int t;cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ": ";
        int s,d,k;cin >> s >> d >> k;
        int ans=0;
        int buns=(s+d)*2;
        int patties=s+d*2;
        int rbuns = k+1;
        int rpatties = k;
        if (buns>=rbuns && patties>=rpatties)
            cout <<"YES" << endl;
        else 
            cout << "NO" << endl;
    }
}