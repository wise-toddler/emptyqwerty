// https://codeforces.com/contest/1907/problem/F
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
// no of peaks

bool isRotatedIncreasing(vi &a)
{
    int n = a.size();
    bool pointOfRotationFound = false;

    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            if (pointOfRotationFound)
            {
                return false;
            }
            pointOfRotationFound = true;
        }
    }

    if (pointOfRotationFound && a[n - 1] > a[0])
    {
        return false;
    }

    return true;
}

bool isRotatedDecreasing(vi &a)
{
    int n = a.size();
    bool pointOfRotationFound = false;

    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] < a[i])
        {
            if (pointOfRotationFound)
            {
                return false;
            }
            pointOfRotationFound = true;
        }
    }

    if (pointOfRotationFound && a[n - 1] < a[0])
    {
        return false;
    }

    return true;
}

bool isIncreasing(vi &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool isDecreasing(vi &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            return false;
        }
    }
    return true;
}

int f(vi &a, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            return i;
    }
    return -1;
    // binary
}

int g(vi &a, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] > a[i])
            return i;
    }
    return -1;
    // binary
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    if (!isDecreasing(a) && !isIncreasing(a) && !isRotatedDecreasing(a) && !isRotatedIncreasing(a))
    {
        cout << "-1" << endl;
        return;
    }

    if (isIncreasing(a))
    {
        cout << "0" << endl;
        return;
    }

    if (isDecreasing(a))
    {
        cout << "1" << endl;
        return;
    }

    if (isRotatedIncreasing(a) && !isRotatedDecreasing(a))
    {
        int index = f(a, n);
        int ans1 = index + 3;
        int ans2 = n - index - 1;
        // cout << index << endl;
        cout << min(ans1, ans2) << endl;
    }
    else if (isRotatedDecreasing(a) && !isRotatedIncreasing(a))
    {
        int index = g(a, n);
        int ans1 = index + 2;
        int ans2 = n - index;
        cout << min(ans1, ans2) << endl;
    }
    else
    {
        int index = f(a, n);
        // cout << index << endl;
        int ans1 = index + 3;
        int ans2 = n - index - 1;
        int ans3 = min(ans1, ans2);
        index = g(a, n);
        // cout << index << endl;
        ans1 = index + 2;
        ans2 = n - index;
        ans3 = min({ans3, ans1, ans2});
        cout << ans3 << endl;
    }
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}