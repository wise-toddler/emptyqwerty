// https://codeforces.com/contest/1886/problem/0
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
    while(t--)
    {
        int n;cin >> n;
        if(n<=6 || n==9)
        {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" <<'\n';
        int x=n;
        int sum =0;
        while(x!=0)
        {
            sum+=x%10;
            x/=10;
        }
        sum%=3;
        if(sum==0)
        {
            cout << 1 << ' ' << 4 <<' '<< n - 5 <<endl;
            continue;
        }
        cout << 1 << ' ' << 2 <<' '<< n - 3 << endl;
        continue;

    }
}