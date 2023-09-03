// // https://atcoder.jp/contests/abc318/tasks/abc318_e
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
// 13
// 9 7 11 7 3 8 1 13 11 10 11 6 13 6 3 1 2 11 1 2 2 3 4 1 11 22 4 31 11 11 

// 1    6
// 3    4
// 6    12
// 7    1  3
// 8    5  
// 9    0
// 10   9
// 11   2  8  10
// 13   7  12

//5
// 2 1 2 1 2


// 1    1 3
// 2    0 2 4