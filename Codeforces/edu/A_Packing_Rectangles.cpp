// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
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
    IOS int h, w, n;
    cin >> h >> w >> n;
    // h=2;w=3;n=10;
    int ans = 0;
    int st = 1;
    int en = INT64_MAX;

    // int en = max(h,w)*n;  // ask sir y it didnt work

    // while ((en / h) * (en / w) < n)
    //     en *= 2; // ask sir y it worked
    // st = en / 2;

    while (st <= en)
    {
        int mid = st + (en - st) / 2;

        if((mid>=h && mid>=w) and ((mid/h) >= n || (mid/w) >= n || ((mid/h)*(mid/w) >= n)))
        {
            ans = mid;
            en = mid - 1;
        }
        else
            st = mid + 1;
    }
    cout << ans << endl;
}