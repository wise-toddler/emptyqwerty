// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/A2?source=facebook
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
signed main()
{
    IOS
    int t;cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Case #" << i << ": ";
        int A,B,C;cin >> A >> B >> C;
        // b>2a  -> only a
        int ans=0;
        {
            int d = C/B;
            int s = C%B/A;
            int bun = (d+s)*2;
            int patty = d*2 + s;
            ans = max(ans, (bun == patty) ? patty - 1 : patty);
        }
        {
            int s = C/A;
            int d = (C%A)/B;
            int bun = (d+s)*2;
            int patty = d*2 +s;
            ans =max(ans,(bun == patty)?patty-1:patty);
        }
        cout << ans << endl;
    }
}