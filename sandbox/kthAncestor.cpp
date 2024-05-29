#include <bits/stdc++.h>
using namespace std;
template <typename T> ostream &operator<<(ostream &os, vector<T> &v)
{
    for (auto &x : v)
        os << x << ' ';
    return os;
}   
// class TreeAncestor
// // {
// // public:
//     vector<vector<int>> dp; // dp[i][j] = 2^jth parent of i
//     // [-1, 0, 0, 1, 1, 2, 2]
//     // TreeAncestor(int n, vector<int> &parent)
//     // {
//         int m = log2(n) + 1;
//         dp = vector<vector<int>>(n, vector<int>(m, -1));
//         for (int i = 0; i < n; i++)
//             dp[i][0] = parent[i];
//         /*
//             -1 -1 -1 -1 
//             0 -1 -1 -1
//             0 -1 -1 -1
//             1  0 -1 -1
//             1  0 -1 -1
//             2  0 -1 -1
//             2  0 -1 -1  
//         */
//         for (int j = 1; j < m; j++) // 2^jth parent of i
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 if (dp[i][j - 1] != -1)
//                     dp[i][j] = dp[dp[i][j - 1]][j - 1]; // 2^jth parent of i = 2^(j-1)th parent of 2^(j-1)th parent of i
//             }
//         }
//         for(auto x: dp)
//             cout << x << endl;
// //     }

    int getKthAncestor(int node, int k)
    {
        int m = dp[0].size();
        for (int i = 0; i < m; i++)
        {
            if (k & (1 << i)) 
            {
                node = dp[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
// };

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
int main()
{
    int n = 7;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};
    int m = log2(n) + 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        dp[i][0] = parent[i];

    for (int j = 1; j < m; j++) 
        for (int i = 0; i < n; i++)
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1]; 
    
    for(auto x: dp)
        cout << x << endl;
    return 0;
}