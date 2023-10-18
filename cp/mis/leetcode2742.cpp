// https://leetcode.com/problems/painting-the-walls/description/
#include <bits/stdc++.h>
using namespace std;
int paintWalls(vector<int> &cost, vector<int> &time)
{
    int n = cost.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.emplace_back(cost[i], time[i]);
    sort(v.begin(), v.end());
    
    for(int i =0;i<n-1;i++)
    {
        if(v[i].first == v[i+1].first)
        {
            int j = i+1;
            while(j<n && v[j].first == v[i].first)
            {
                j++;
            }
            reverse(v.begin()+i,v.begin()+j);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    int pp = 0, fp = n - 1;
    int ans = 0;

    for (int i = 0; i < n and i <= fp; i++)
    {
        ans += v[i].first;
        fp -= v[i].second;
    }
    return ans;
}
int main()
{
    // [26,53,10,24,25,20,63,51]
    // [1,1,1,1,2,2,2,1]
    // vector<int> cost = {26,53,10,24,25,20,63,51};
    // vector<int> time = {1,1,1,1,2,2,2,1};
    vector<int> cost = {3 ,3 ,5};
    vector<int> time = {1, 1, 2};
    cout << paintWalls(cost, time) << endl;
}
