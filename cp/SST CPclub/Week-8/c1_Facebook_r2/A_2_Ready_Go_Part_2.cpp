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
#define TxtIO freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
// #define TxtIO freopen("ithtestcase.txt", "r", stdin);freopen("output.txt", "w", stdout);

bool adcheck1(vector<string> &v, int r, int c, char ch) // check if adjecent cell is ch
{
    int n = v.size(), m = v[0].size();
    // if(r<0 || c<0|| r>=n || c>=m) return 0;
    if (r - 1 >= 0 && v[r - 1][c] == ch)return 1;
    if (r + 1 < n && v[r + 1][c] == ch)return 1;
    if (c - 1 >= 0 && v[r][c - 1] == ch)return 1;
    if (c + 1 < m && v[r][c + 1] == ch)return 1;
    return 0;
}
int w1(vector<string> &v, int r, int c) // find no of adjecent emty cells
{
    int cnt = 0;
    int n = v.size(), m = v[0].size();
    if (r - 1 >= 0 && v[r - 1][c] == '.')cnt++;
    if (r + 1 < n && v[r + 1][c] == '.')cnt++;
    if (c - 1 >= 0 && v[r][c - 1] == '.')cnt++;
    if (c + 1 < m && v[r][c + 1] == '.')cnt++;
    return cnt;
}
pii mark(vector<string> &v, int r, int c) 
{
    int n = v.size(), m = v[0].size();
    if (r - 1 >= 0 && v[r - 1][c] == '.')return {r - 1, c};
    if (r + 1 < n && v[r + 1][c] == '.')return {r + 1, c};
    if (c - 1 >= 0 && v[r][c - 1] == '.')return {r, c - 1};
    if (c + 1 < m && v[r][c + 1] == '.')return {r, c + 1};
    return {-1, -1};
}
void marker(vector<string> &v, int r, int c, set<pii> &s,map<pii,int> &donee)
{
    int n = v.size(), m = v[0].size();
    if(r<0 || c<0|| r>=n || c>=m) return;
    if (r - 1 >= 0 && v[r - 1][c] == 'W' && s.find({r - 1, c}) == s.end())
    {
        donee[{r-1,c}]=1;
        s.insert({r - 1, c});
        marker(v, r - 1, c, s, donee);
    }
    if (r + 1 < n && v[r + 1][c] == 'W' && s.find({r + 1, c}) == s.end())
    {
        donee[{r+1,c}]=1;
        s.insert({r + 1, c});
        marker(v, r + 1, c, s, donee);
    }
    if (c - 1 >= 0 && v[r][c - 1] == 'W' && s.find({r, c - 1}) == s.end())
    {
        donee[{r,c-1}]=1;
        s.insert({r, c - 1});
        marker(v, r, c - 1, s, donee);
    }
    if (c + 1 < m && v[r][c + 1] == 'W' && s.find({r, c + 1}) == s.end())
    {
        donee[{r,c+1}]=1;
        s.insert({r, c + 1});
        marker(v, r, c + 1, s, donee);
    }
}

bool grch(vector<string> &v, int r, int c, set<pii> &s)
{
    for (auto q : s)
    {
        if (adcheck1(v, q.first, q.second, '.'))
            return 0;
    }
    return 1;
}
int solve()
{
    int r, c;
    cin >> r >> c;
    vector<string> v(r);
    fo1(i, 0, r, 1) cin >> v[i];
    set<vi> st;
    fo1(i, 0, r, 1)
    {
        fo1(j, 0, c, 1)
        {
            if (v[i][j] == 'W' && w1(v, i, j) == 1)
            {
                st.insert({i, j});
            }
        }
    }
    int maax = 0;
    map<pii, int> mp;
    map<pii, int> donee;
    for (auto &w : st)
    {
        // marked W
        set<pii> s;
        int x = w[0], y = w[1];
        pii p = mark(v, x, y);

        if(x<0 || y<0|| x>=r || y>=c) continue;
        if(p.first<0 || p.second<0|| p.first>=r || p.second>=c) continue;

        v[p.first][p.second] = 'B';
        if(donee[{x,y}]==1) continue;

        donee[{x,y}]=1;
        s.insert({x, y});
        marker(v, x, y, s,donee);
        if (grch(v, x, y, s))
            mp[p]+=(int)s.size();
        v[p.first][p.second] = '.';
    }
    for(auto q:mp)
    {
        maax=max(maax,q.second);
    }
    return maax;
}
signed main()
{
    IOS
    TxtIO
    int t;
    cin >> t;
    fo1(i, 1, t + 1, 1)
    {
        cout << "Case #" << i << ": ";
        cout << solve() << endl;
    }
}
