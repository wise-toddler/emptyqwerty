// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/H
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
    string s;cin>>s;
    int nb,ns,nc;cin>>nb>>ns>>nc;
    int pb,ps,pc;cin>>pb>>ps>>pc;
    int r;cin>>r;
    int rb=0,rs=0,rc=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B') rb++;
        else if(s[i]=='S') rs++;
        else rc++;
    }

    int wB= min((rb==0?INT64_MAX:nb/rb),min((rs==0?INT64_MAX:ns/rs),(rc==0?INT64_MAX:nc/rc)));
    nb-=wB*rb;
    ns-=wB*rs;
    nc-=wB*rc;
    int st=0,en=1e14;
    int ans=0;
    while(st<=en)
    {
        int mid = st+(en-st)/2;
        int cost = max(0LL,mid*rb-nb)*pb + max(0LL,mid*rs-ns)*ps + max(0LL,mid*rc-nc)*pc;
        if(cost<=r)
        {
            ans = mid;
            st = mid+1;
        }
        else
            en = mid-1;
    }
    cout << ans+wB << endl;

}