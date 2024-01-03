// https://www.codechef.com/START107C/problems/ADJFLIP
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
void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    // if(s==string(n,'1') || s==string(n,'0'))
    // {
    //     cout <<"Yes" << endl;
    //     return;
    // }
    // count the number of 1s and 0s with 

    int one = 0;
    int zero = 0;

    fo1(i,0,n,1)
    {
        char c = s[i];
        int e=0;
        while(i<n && s[i]==c)
        {
            e++;
            i++;
        }
        if(e&1) 
        {
            if(c=='1') one++;
            else zero++;
        }
        i--;
    }
    // cout << one << " " << zero << endl;
    if(one == 0 || zero == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}