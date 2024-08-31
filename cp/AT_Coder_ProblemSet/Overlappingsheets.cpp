// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-5.md
// https://atcoder.jp/contests/abc318/tasks/abc318_b
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;cin >> t;
    vector<vector<int>> v(100,vector<int>(100,0));
    while(t--)
    {   
        int ai,bi,ci,di;cin >> ai >> bi >> ci >> di;
        for (int i=0;i<100;i++)
        {
            for (int j=0;j<100;j++)
            {
                if (i>=ai && i<bi && j>=ci && j<di)
                    v[i][j]=1;
            }
        }
    }
    int ans=0;
    for (int i=0;i<100;i++)
    {
        for (int j=0;j<100;j++)
        {
            if (v[i][j]==1)
                ans++;
        }
    }
    cout << ans << endl;
}