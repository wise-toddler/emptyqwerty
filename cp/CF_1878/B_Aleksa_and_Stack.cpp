// https://codeforces.com/contest/1878/problem/B
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
        vi a(n);
        a[0] = 10;  
        a[1] = 11;
        cout << 10 << ' '<<11 << ' ';
        n-=2;

        // for(int i = 12,e=2;n;i++)
        // {
        //     if( ( 3 * i ) % ( a[e-1] * a[e-2] ) != 0 )
        //     {
        //         a[e] = i;
        //         cout << i << ' ';
        //         e++;
        //         n--;
        //     }
        // }
        for (int i = 12; n; i++)
        {
            int a = 10;
            int b = 11;
            if ((3 * i) % (a+b) != 0)
            {
                a = b;
                b = i;
                cout << i << ' ';
                n--;
            }
        }
        cout << endl;
    }
}