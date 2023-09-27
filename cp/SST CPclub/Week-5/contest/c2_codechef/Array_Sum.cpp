// https://www.codechef.com/START102D/problems/SUMARRAY
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
        cout << i << ' ';
        print(v[i]);
    }
}

signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (3 * (n / 2) > k || n % 4 != 0 && k % 2 == 0 || n % 4 == 0 && k % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }
        vi a(n, 1);
        for (int i = 0; i < n / 2; i++)
        {
            a[i] += 1;
        }
        k -= 3 * ((n / 2));
        int q = k / n;
        int r = k % n;
        for (int i = 0; i < n; i++)
            a[i] += q;
        while (r >= 2)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (r >= 2)
                {
                    a[i] += 2;
                    r -= 2;
                }
            }
        }
        if(a[n-1]>100000 || a[0]>100000)
        {
            cout<< -1 <<endl;
            continue;
        }
        print(a);
    }
}
// n = 4 k = 20
// 2 2 1 1
// 14
// 14/4 =3
// 5 5 4 4
// 14%4 = 2
// 7 5 4 4