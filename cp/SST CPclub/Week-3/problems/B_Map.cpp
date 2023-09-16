// https://codeforces.com/group/isP4JMZTix/contest/392597/problem/B
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
    unordered_map<string,int> hm;
    while(t--)
    {
        string s;cin >> s;
        // make hashmap
        // hashMap<string,int> hm;
        hm[s]++;
        if(hm[s] == 1)
            cout << "OK" << endl;
        else
            cout << s << hm[s]-1 << endl;
    }
    
}