// https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-2/problems/A1
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

// check adjacent cells if they have marked W or B
bool adcheck1(vector<string> &v, int r, int c, char ch)
{
    int n=v.size(),m=v[0].size();
    if(r-1>=0 && v[r-1][c]==ch) return 1;
    if(r+1<n && v[r+1][c]==ch) return 1;
    if(c-1>=0 && v[r][c-1]==ch) return 1;
    if(c+1<m && v[r][c+1]==ch) return 1;
    return 0;
}
bool adcheckAll(vector<string> &v, int r, int c, set<pii> &s)
{
    int n=v.size(),m=v[0].size();
    if(r-1>=0 && (v[r-1][c]=='W' && s.find({r-1,c})==s.end())) return 0;
    if(r+1<n && v[r+1][c]=='W' && s.find({r+1,c})==s.end()) return 0;
    if(c-1>=0 && v[r][c-1]=='W' && s.find({r,c-1})==s.end()) return 0;
    if(c+1<m && v[r][c+1]=='W' && s.find({r,c+1})==s.end()) return 0;
    return 1;
}
int w1(vector<string> &v, int r, int c) // find W with 1 empty cell
{
    int cnt=0;
    int n=v.size(),m=v[0].size();
    if(r-1>=0 && v[r-1][c]=='.') cnt++;
    if(r+1<n && v[r+1][c]=='.') cnt++;
    if(c-1>=0 && v[r][c-1]=='.') cnt++;
    if(c+1<m && v[r][c+1]=='.') cnt++;
    return cnt;
}
pii mark(vector<string> &v, int r, int c)
{
    int n=v.size(),m=v[0].size();
    if(r-1>=0 && v[r-1][c]=='.') return {r-1,c};
    if(r+1<n && v[r+1][c]=='.') return {r+1,c};
    if(c-1>=0 && v[r][c-1]=='.') return {r,c-1};
    if(c+1<m && v[r][c+1]=='.') return {r,c+1};
    return {-1,-1};
}
void marker(vector<string> &v, int r, int c,set<pii> &s)
{
    int n=v.size(),m=v[0].size();
    
    if(r-1>=0 && v[r-1][c]=='W' && s.find({r-1,c})==s.end()) 
    {
        s.insert({r-1,c});
        marker(v,r-1,c,s);
    }
    if(r+1<n && v[r+1][c]=='W' && s.find({r+1,c})==s.end()) 
    {
        s.insert({r+1,c});
        marker(v,r+1,c,s);
    }
    if(c-1>=0 && v[r][c-1]=='W' && s.find({r,c-1})==s.end()) 
    {
        s.insert({r,c-1});
        marker(v,r,c-1,s);
    }
    if(c+1<m && v[r][c+1]=='W' && s.find({r,c+1})==s.end()) 
    {
        s.insert({r,c+1});
        marker(v,r,c+1,s);
    }
}
// bool groupcap(vector<string> &v, int r, int c, set<pii> &s)
// {
//     int n=v.size(),m=v[0].size();
//     if(adcheck1(v,r,c,'.')) return 0;
//     if(adcheckAll(v,r,c,s)) return 1;
//     s.insert({r,c});
//     return 0;
// }
bool grch(vector<string> &v, int r, int c, set<pii> &s)
{
    for(auto q:s)
    {
        if(adcheck1(v,q.first,q.second,'.')) 
            return 0;
    }
    return 1;
}
bool solve()
{
    int r,c;cin>>r>>c;
    vector<string> v(r);
    fo1(i,0,r,1)cin>>v[i];
    set<pii> st;
    fo1(i,0,r,1)
    {
        fo1(j,0,c,1)
        {
            if(v[i][j]=='W' && w1(v,i,j)==1)
            {
                st.insert({i,j});
            }
        }
    }
    for(auto w:st)
    {
        // cout << st.top().first << " " << st.top().second << endl;
        // st.pop();
        //marked W 
        set<pii> s;
        int x=w.first,y=w.second;
        pii p=mark(v,x,y);
        // deb(x)deb(y)
        // deb(p.first)deb(p.second)
        v[p.first][p.second]='B';
        marker(v,x,y,s);
        if(grch(v,x,y,s )) 
            return 1;
        v[p.first][p.second]='.';
    }
    return 0;
}
signed main()
{
    IOS
    // TxtIO
    int t;
    cin >> t;
    fo1(i,1,t+1,1)
    {
        cout << "Case #" << i << ": ";
        if(solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}