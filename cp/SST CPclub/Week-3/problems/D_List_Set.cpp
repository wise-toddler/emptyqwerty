// https://codeforces.com/group/isP4JMZTix/contest/392597/problem/D
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
    unordered_set<int> hs;
    while(n--)
    {
        int x;cin >> x;
        hs.insert(x);
    }
    cout << hs.size() << endl;
    
}