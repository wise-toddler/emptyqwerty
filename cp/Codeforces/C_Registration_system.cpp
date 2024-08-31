// https://codeforces.com/contest/4/problem/C
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
    map<string,int> st;
    while(t--)
    {
        int n=st.size();
        string s;cin >> s;
        st[s]++;
        if(st[s]==1)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << s << st[s]-1 << endl;
           
        }

    }
}