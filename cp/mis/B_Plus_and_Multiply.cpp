// https://codeforces.com/problemset/problem/1542/B
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
        int n,a,b;cin >> n >> a >> b;
        if(a==1)
        {
            cout << (n%b==1%b?"Yes":"No") << endl;
            continue;
        }
        for(int i =1;i<=n;i*=a)
        {
            if(n%b == i%b)
            {
                cout << "Yes" << endl;
                goto end;
            }
        }
        cout << "No" << endl;
        end:;
    }
}
// n = 3000;
// +- 1;
// 