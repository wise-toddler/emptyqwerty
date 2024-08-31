// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
signed main()
{
    IOS int n, s;
    cin >> n >> s;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    int x = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        x += a[i];
        while (x >=s && j < n)
        {
            ans += (n - i);
            x -= a[j];
            j++;
            // if(x>=s)
        }
    }
    cout<<ans<<endl;
    // cout << ((n + 1) * n) / 2 - ans << endl;
}