// https: // atcoder.jp/contests/abc326/tasks/abc326_d
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
string a,b;
int n,w=1;
bool done=0;
string abc = "ABC";
set<char> q;

bool containabc()
{
    set<char> s;
    s.insert(all(a));
    if(s!=q) return 0;
    s.clear();
    s.insert(all(b));
    if(s!=q) return 0;
    return 1;
}
vector<string> bod;
bool colcheck(char q,int r,int c)
{
    for(int i=0;i<r;i++)
        if(bod[i][c]==q)
            return 0;
    return 1;
}
bool rowcheck(char q,int r,int c)
{
    for(int i=0;i<c;i++)
        if(bod[r][i]==q)
            return 0;
    return 1;
}
bool dotabove(int r,int c)
{
    for(int i=r-1;i>=0;i--)
        if(bod[i][c]!='.')
            return 0;
    return 1;
}
bool dotleft(int r,int c)
{
    for(int i=c-1;i>=0;i--)
        if(bod[r][i]!='.')
            return 0;
    return 1;
}
void bt(int r,int c)
{
    if(done==1)
        return;
    if(r==n && done==0)
    {
        // check that all rows and columns have A,B,C
        for(int i=0;i<n;i++)
        {
            set<char> s;
            for(int j=0;j<n;j++)
                if(bod[i][j]!='.')
                    s.insert(bod[i][j]);

            if(s!=q)return;
            s.clear();

            for(int j=0;j<n;j++)
                if(bod[j][i]!='.')
                    s.insert(bod[j][i]);
            if(s!=q)
                return;
        }
        done=1;
        cout << "Yes" << endl;
        for(int i=0;i<n;i++)
            cout << bod[i] << endl;
       exit(0);
    }
    if(c==n)
    {
        //check that if this row has A,B,C
        set<char> s;
        for(int i=0;i<n;i++)
            if(bod[r][i]!='.')
                s.insert(bod[r][i]);
        if(s!=q)
            return;
        bt(r+1,0);
        return;
    }
    bt(r,c+1);
    for (int i = 0; i < 3; i++)
    {
        char ch = abc[i];
        if(colcheck(ch,r,c) && rowcheck(ch,r,c))
        {
            if(dotabove(r,c) && b[c]!=ch)
                continue;
            if(dotleft(r,c) && a[r]!=ch)
                continue;
            bod[r][c]=ch;
            bt(r,c+1);
            bod[r][c]='.';
        }
    }

}

void solve()
{
    cin >> n;
    bod.resize(n,string(n,'.'));
    cin >> a >> b;

    q.insert('A');
    q.insert('B');
    q.insert('C');
    bt(0,0);
    if(done==0)
        cout << "No" << endl;   

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