// https://www.spoj.com/problems/RPLD/
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
    for(int t1=1;t1<=t;t1++)
    {
        bool flag = true;
        int n,r;cin >> n >> r;
        map<int,set<int>> mp;
        for(int i=0;i<r;i++)
        {
            int x,y;cin >> x >> y;
            int size = mp[x].size();
            mp[x].insert(y);
            if(size == mp[x].size() && flag)
            {
                flag = false;
            }
        }
        if(flag)
            cout << "Scenario #" << t1 << ": possible" << endl;
        else
            cout << "Scenario #" << t1 << ": impossible" << endl;
    }
}