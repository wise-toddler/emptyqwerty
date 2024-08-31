// https://codeforces.com/contest/903/problem/C
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
    int n;cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;cin >> x;
        mp[x]++;
    }
    int maxa = 0;
    for(auto it : mp)
        maxa = max(maxa,it.second);
    cout << maxa << endl;
}