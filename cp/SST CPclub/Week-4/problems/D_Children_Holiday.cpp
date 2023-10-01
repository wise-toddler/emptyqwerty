// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
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
int m, n;
vii a;
void print(vi v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // cout << i << ' ';
        print(v[i]);
    }
}

int contribution[1000000];

int f(vi &a, int mid)
{
    int ans = 0;
    int t = a[0]; // time taken to inflate one balloon
    int z = a[1]; // number of balloons after which rest in needed
    int y = a[2]; // rest required after inflating z balloons
    ans +=( mid / ((t * z) + y))*z;
    if (mid % ((t * z) + y) >= t * z)
        ans += z;
    else
        ans += (mid % ((t * z) + y)) / t;
    return ans;
}


bool good(int mid)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = f(a[i], mid);
        contribution[i] = cur;
        c += cur;
    }
    return c >= m;
}

signed main()
{
    IOS;
    cin >> m >> n;

    a = vector<vector<int>>(n, vector<int>(3));
    
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    int st = 0, en = 1e15;
    int ans = 0;

    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (good(mid))
        {
            ans = mid;
            en = mid - 1;
        }
        else
            st = mid + 1;
    }

    cout << ans << endl;

    good(ans);

    int done = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = min(contribution[i], m - done);
        done += cur;
        cout << cur << ' ';
    }
}
