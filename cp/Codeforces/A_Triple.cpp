// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-2/Set-1.md
// https://codeforces.com/group/isP4JMZTix/contest/380288/problem/A
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
// int solve(vi v)
// {
//     for(int i=0;i<2e5;i++)
//         if(v[i]>=3)
//         {
//             return i;
//         }
//     return -1;
// }
signed main()
{
    IOS
    int t;cin>>t;
    while(t--)
    {
        int n;cin >> n;
        vi v(n+1);
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int q;cin >> q;
            v[q-1]++;
            if(v[q-1]==3)
                ans=q;
        
        }
        cout << ans << endl;
    }
}
// #include <iostream>
// #define int long long
// using namespace std;

// signed main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         const int maxQ = 2e5; // Maximum possible value of q
//         int v[maxQ] = {0};
//         int ans = -1;
        
//         for (int i = 0; i < n; i++) {
//             int q;
//             cin >> q;
//             v[q - 1]++;
//             if (v[q - 1] == 3) {
//                 ans = q;
//             }
//         }
        
//         cout << ans << endl;
//     }
    
//     return 0;
// }
