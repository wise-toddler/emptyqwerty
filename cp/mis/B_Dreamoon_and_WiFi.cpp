// https://codeforces.com/problemset/problem/476/B
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define cout cout << fixed << setprecision(12)
int nCr(int m, int n)
{
    double ans = 1.0;
    for(int i=0;i<n;i++)
    {
        ans *= (m-i);
        ans /= (i+1);
    }
    return (int)ans;
}
signed main()
{
    // IOS
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    map<char,int> m1,m2;
    for(char c:s1)m1[c]++;
    for(char c:s2)m2[c]++;
    int p = m2['?'];
    // debug(p)
    // int q = m2['+'];
    int idealpos = m1['+'] - m1['-'];
    int curpos = m2['+'] - m2['-'];
    double ans = 0.0;
    // cout << nCr(2,1) << endl;
    int x = abs(idealpos - curpos);
    if(p < x)
        ans = 0.0;
    else
    {
        int y = p - x;
        if(y&1)
            ans = 0.0;
        else
            ans = pow(0.5,p)*nCr(p,y/2);
    }
    cout << ans << endl;

}
/*
00
01
10
11



6/16
3/8

0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
4*3
---
2*1*(2^4)
*/
