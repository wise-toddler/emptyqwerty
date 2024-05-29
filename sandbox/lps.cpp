#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl;
// longest palindromic subsequenece
int lps(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0)); 
    // dp[i][j] = length of longest palindromic subsequence in s[i..j]
    dp[0][0] = 1;
    for(int i=0;i<n;i++) 
    {
        dp[i][i] = 1;
        for(int j=i-1;j>=0;j--)
        {
            if(s[i]==s[j]) dp[i][j] = 2+dp[i-1][j+1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
        }
    } 
    return dp[n-1][0];
}
int main()
{
    string s;
    cin >> s;
    cout << lps(s) << endl;
}
