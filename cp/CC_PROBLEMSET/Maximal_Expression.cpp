// https://www.codechef.com/START107C/problems/MAXIMALEXP
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
    int n,k;cin>>n>>k;
    cout<<((n%k)/2)<<endl;
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

/*
13 5 
x%k * (n-x)%k

1 2 3 4 5 6 7 8 9 10 11 12 13
12 11 10 9 8 7 6 5 4 3 2 1 0
1 2 3 4 0 1 2 3 4 0 1 2 3
2 1 0 4 3 2 1 0 4 3 2 1 0
2 2 0 16 0 2 2 0 16 0 2 2 0


9 2 
1 2 3 4 5 6 7 8 9
8 7 6 5 4 3 2 1 0
1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0
0 0 0 0 0 0 0 0 0

*/