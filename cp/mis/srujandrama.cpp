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
int n, m;
vii a,done;

// void marker(int i,int j)
// {
//     if(i<0 || i>=n || j<0 || j>=m ||a[i][j]==0 || done[i][j]) return;

//     done[i][j]=1;
//     marker(i+1,j);
//     marker(i-1,j);
//     marker(i,j+1);
//     marker(i,j-1);
// }
bool uporleft(int i,int j)
{
    if(i==0 || j==0) 
    {
        if(i==j) return 1;
        if(i==0) return a[i][j-1]==0;
        if(j==0) return a[i-1][j]==0;
        
    }

    // if(uporleft(i-1,j)) return 1;
    // if(uporleft(i,j-1)) return 1;

    return a[i-1][j]==0 && a[i][j-1]==0;
}
signed main()
{
    IOS
    cin>>n>>m;
    a.resize(n,vi(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    done.resize(n,vi(m,0)); 
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(done[i][j]) continue;
            if( a[i][j]!=0 ) 
            {
                // marker(i,j);
                if(uporleft(i,j))
                {
                    c++;
                    continue;
                }
            }
        }
    }
    cout << c << endl;


}