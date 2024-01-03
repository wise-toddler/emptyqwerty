#include <bits/stdc++.h>
using namespace std;
struct TreeNode 
{
    int value;
    int nodeno;
    vector<TreeNode*> children;
    TreeNode(int val, int no) : value(val), nodeno(no) {}
};
TreeNode* constructTree(vector<vector<int>>& edges, vector<int>& values, int currentNode) 
{
    TreeNode* node = new TreeNode(values[currentNode], currentNode);
    for (auto &edge : edges) 
    {
        if (edge[0] == currentNode) 
        {
            node->children.push_back(constructTree(edges, values, edge[1]));
        }
    }
    return node;
}
long long dp[1000007][18];
long long fa(TreeNode* node ,long long f,int k)
{
    int val = node->value;
    if((node->children).size()==0)
    {
        return dp[node->nodeno][f]=max((val/(1<<f))-k,val/(1<<(f+1)));
    }
    if(dp[node->nodeno][f]!=-1)
        return dp[node->nodeno][f];
    long long a = (val/(1<<f))-k;
    long long b = val/(1<<(f+1));
    for(auto &i:node->children)
    {
        a+=fa(i,f,k);
        b+=fa(i,f+1,k);
    }
    return dp[node->nodeno][f]=max(a,b);
}
int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) 
{  
    for(auto &i:edges)
        if(i[0]>i[1])
            swap(i[0],i[1]);
    memset(dp,-1,sizeof(dp));
    TreeNode* root = constructTree(edges, coins, 0);
    return fa(root, 1, k);
    
}
int main()
{
    // vector<vector<int>> edges = {{0,1},{1,2},{2,3}};
    // vector<int> coins = {10,10,3,3};
    // int k = 5;
    // cout << maximumPoints(edges, coins, k) << endl;
    cout << fixed << setprecision(50) << log2(125)/log2(5) << endl;
}
