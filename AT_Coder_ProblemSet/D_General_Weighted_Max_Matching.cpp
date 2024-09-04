// https://atcoder.jp/contests/abc318/tasks/abc318_d
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-5.md
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
int n;
vii a(20, vi(20, 0));
const int N = 1 << 16;
int dp[N];

int remain(int taken, int rem)
{
    if(dp[taken] != -1)
        return dp[taken];

    if(rem <= 1)
        return 0;
    
    int ans = 0;
    for(int i = 0; i < n; ++i) 
    {
        for(int j = i + 1; j < n; ++j) 
        {
            bool isITaken = taken & (1 << i);
            bool isJTaken = taken & (1 << j);
            if(!isITaken and !isJTaken) 
            {
                taken ^= (1 << i);
                taken ^= (1 << j); 
                ans = max(ans, a[i][j] + remain(taken, rem - 2));
                taken ^= (1 << i);
                taken ^= (1 << j); 
            }
        }
    }
    
    return dp[taken] = ans;
}

signed main()
{
    IOS
    cin >> n;

    for(int i = 0; i < n - 1; ++i) 
        for(int j = i + 1; j < n; ++j) 
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    

    for(int i = 0; i < N; ++i) 
        dp[i] = -1;

    cout <<remain(0, n) <<endl;
} 


// int remain(vector<bool> &taken, int rem)
// {
//     if(dp.count(taken))
//         return dp[taken];

//     if(rem <= 1)
//         return 0;
    
//     int ans = 0;
//     for(int i = 0; i < n; ++i) {
//         for(int j = i + 1; j < n; ++j) {
//             if(!taken[i] and !taken[j]) {
//                 taken[i] = taken[j] = 1; 
//                 ans = max(ans, a[i][j] + remain(taken, rem - 2));
//                 taken[i] = taken[j] = 0; 
//             }
//         }
//     }
    
//     return dp[taken] = ans;
// }