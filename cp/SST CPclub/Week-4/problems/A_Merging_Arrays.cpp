// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/A
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
    int n,m;cin >> n >> m;
    multiset<int> st;
    for(int i =0;i<n;i++)
    {
        int x;cin >> x;
        st.insert(x);
    }
    for(int i =0;i<m;i++)
    {
        int x;cin >> x;
        st.insert(x);
    }
    for(auto it : st)
        cout << it << ' ';
}