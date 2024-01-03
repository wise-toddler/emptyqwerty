// https://atcoder.jp/contests/abc327/tasks/abc327_c
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
bool colcheck(vector<vector<char>> &b, int r, int c)
{
    for (int i = r + 1; i < 9; i++)
        if (b[r][c] == b[i][c])
            return 1;
    return 0;
}
bool rowcheck(vector<vector<char>> &b, int r, int c)
{
    for (int i = c + 1; i < 9; i++)
        if (b[r][c] == b[r][i])
            return 1;
    return 0;
}
bool boxcheck(vector<vector<char>> &b, int r, int c)
{
    int x = r / 3 * 3;
    int y = c / 3 * 3;
    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            if ((i != r || j != c) && b[r][c] == b[i][j])
                return 1;
    return 0;
}

bool isValidSudoku(vector<vector<char>>& board) 
{
    for(int i =0;i<9;i++)
        for(int j=0;j<9;j++)
            if(rowcheck(board,i,j) || colcheck(board,i,j) || boxcheck(board,i,j))
                return 0;   
    return 1;
}
void solve()
{
    vector<vector<char>> board(9,vector<char>(9));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    cout << (isValidSudoku(board)?"Yes":"No") << endl;
    
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}