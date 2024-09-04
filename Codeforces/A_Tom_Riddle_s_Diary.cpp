// https://codeforces.com/contest/855/problem/A
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
    set<string> st;
    while(t--)
    {
        int size = st.size();
        string s;cin >> s;
        st.insert(s);
        if(size == st.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}