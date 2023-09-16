// https://codeforces.com/group/isP4JMZTix/contest/392597/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()

int extra(int n) {return n/3 + (n%30>=23) + (n%30>=13) + 2*(n/30);}

signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n;cin >> n;
        int ans =extra(n);
        int counted = 0;
        do
        {
            counted += ans;
            n+=ans;
            ans = extra(n)-counted;
        } while(0 != ans);
        cout << n<< endl;
    }
}