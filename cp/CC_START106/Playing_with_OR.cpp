// https://www.codechef.com/START106C/problems/FIZZBUZZ2304
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
    vi a(n);
    for(int &i:a)cin>>i;
    int i =0,j=k-1;
    int ans = 0;
    stack<int> s1,s2;
    fo1(q,0,j+1,1)
    {
        if(a[q]&1)
            s2.push(q);
    }
    if(s2.size())ans++;
    j++;
    while(j<n)
    {
        if(s1.empty())
        {
            // shift from s2 to s1
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        if(a[j]&1)
            s2.push(j);
        
        while(s1.size() and s1.top()<j-k+1)
            s1.pop();
        if(s2.size() || s1.size()) ans++;
        j++;
    }
    cout<<ans<<endl;
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


// 1 2 3 4 5 6 7 8 9
// 1 0 1 0 1 0 1 0 1
// k = 3
/*
    2 4 
*/