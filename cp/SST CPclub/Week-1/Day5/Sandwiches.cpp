// https://atcoder.jp/contests/abc318/tasks/abc318_e
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-5.md

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main()
// {
//     long long int n;cin >> n;
//     vector<vector<long long int>> v(n,vector<long long int>(2));
//     for (long long int i=0;i<n;i++)
//     {
//         cin >> v[i][0];
//         v[i][1]=i;
//     }
//     v=sort(v);
//     for(long long int i=0;i<n;i++)
//         cout << v[i][0] << " " << v[i][1] << endl;
//     long long int ans=0;
//     for(long long int i=0;i<n;i++)
//     {
//         long long int e=1;
//         while(e+i<n && v[i][0]==v[i+e][0])
//         {
//             ans+=(v[i+e][1]-v[i][1]-1)-(e-1);
//             e++;
//         }
//     }
//     cout << ans;
// }
// time complexity: O(nlogn) space complexity: O(n) 
// time limit exceeded

#include<iostream>
#include<vector>
using namespace std;

#define int long long int
// void print(vector<int>& a)
// {
//     for(auto i:a)
//         cout << i << " ";
//     cout << endl;
// }


int solve(vector<int>& a)
{
    int n =a.size();
    int ans=0;
    int sum=0;
    vector<int> b;
    for(int i=0;i<n-1;i++)
    {
       b.push_back(a[i+1]-a[i]-1);
    }
    // cout << "b: ";
    // print(b);
    for(int i=n-1;i>0;i--)
    {
        ans+=(n-i)*i*b[i-1];
    }
        // cout << "ans: " << ans << endl;

    return ans;
}


signed main()
{
    int n;cin >> n;
    vector<vector<int>> v(3e5);
    for (int i =0;i<n;i++)
    {
        int x;cin >>x;  
        v[x].push_back(i);
    }

    int ans=0;
    for(int i = 0;i <3e5;i++)
    {
        if(v[i].size()>1)
        {
            // cout << "v[i]: ";
            // print(v[i]);
            ans+=solve(v[i]);
            // cout << endl;
            // cout << solve(v[i]) << endl;
        }
    }
    cout << ans;
}
