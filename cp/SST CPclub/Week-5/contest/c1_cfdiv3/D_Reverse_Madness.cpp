// https://codeforces.com/contest/1878/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
// largest smallest or equal binary search
int binSear(vi &a,int x)
{
    int st = 0;
    int en = a.size()-1;
    int ans = -1;
    while(st<=en)
    {
        int mid = st+(en-st)/2;
        if(a[mid]<=x)
        {
            ans = mid;
            st = mid+1;
        }
        else
            en = mid-1;
    }
    return ans;
}
string revsubstr(string s,int l,int r)
{
    string ans = s;
    for(int i=l-1,j=r-1;i<j;i++,j--)
        swap(ans[i],ans[j]);    
    return ans;
}
signed main()
{
    IOS
    int t;cin >> t;
    while(t--)
    {
        int n,k;cin >> n >> k;
        string s;cin >> s;
        // cout << endl << "debug : " << s<<endl;
        vi l(k),r(k);
        for(int i=0;i<k;i++) cin >> l[i] ;
        for(int i=0;i<k;i++) cin >> r[i] ;
        int q;cin >> q;
        string ans=s;
        while(q--)
        {
            int x;cin >> x;
            int index = binSear(l,x);
            int a = min(x,l[index]+r[index]-x);
            int b = max(x,l[index]+r[index]-x);
            if(a!=b)
                ans = revsubstr(ans,a,b);
        }
        cout << ans << endl;
    }
    // vi a = {1,2,3,4,5,6,7,8,9,10};
    // cout << binSear(a,1);
}