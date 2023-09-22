// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/B?source=facebook
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
        cout<<"Case #"<<i<<": ";
        int r,c,a,b;cin >> r >> c >> a >> b;
        if(r>c || (r==c && r&1) )
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}