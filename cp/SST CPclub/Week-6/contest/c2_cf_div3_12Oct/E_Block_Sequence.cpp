// https://codeforces.com/contest/1881/problem/E
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

vi dp;
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        //cout << i << ' ';
        print(v[i]);
    }
}

int solve(vector<int> &a, int pos) 
{

    if(pos == a.size()) {
        return 0;
    }

    if(dp[pos] != -1) {
        return dp[pos];
    }

    // delete this index pos
    int deleteAns = 1 + solve(a, pos + 1);

    // don't delete this index
    int lastIndex = pos + a[pos];
    int keepAns = INT_MAX;

    if(lastIndex < a.size()) {
        keepAns = solve(a, lastIndex + 1);
    }

    return dp[pos] = min(deleteAns, keepAns);
}

signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        vi a(n);
        for(int &i:a)cin >> i;
        dp = vi(n, -1);
        cout << solve(a, 0) << endl;
        // print(dp);
    }
    return 0;
}
/*
    1 <= L <= R <= 1e18

    How many lying in the range [L, R] have their digit sum = 10?

    L = 50, R = 92

    55, 64, 73, 82, 91

    ans = 5

*/
