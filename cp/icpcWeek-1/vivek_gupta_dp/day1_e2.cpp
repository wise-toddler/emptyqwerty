// N queens 
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
int n;
vector<string> board;
vector<vector<string>> ans;
bool can(int r,int c)
{
    int dy[]={-1,0,1};
    for(int i =0 ; i<3;i++)
    {
        int x=r,y=c;
        while(x>=0 && x<n && y>=0 && y<n)
        {
            if(board[x][y]=='Q')
                return false;
            x-=1;
            y+=dy[i];
        }
    }
    return true;
}
void solve(int i)
{
    if(i==n)
    {
        ans.pb(board);
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(can(i,j))
        {
            board[i][j]='Q';
            solve(i+1);
            board[i][j]='.';
        }
    }
}
signed main()
{
    IOS
    cin>>n;
    board.resize(n,string(n,'.'));
    solve(0);
    for(auto x:ans)
    {
        for(auto y:x)
            cout <<y<<endl;
        cout <<endl;
    }
}