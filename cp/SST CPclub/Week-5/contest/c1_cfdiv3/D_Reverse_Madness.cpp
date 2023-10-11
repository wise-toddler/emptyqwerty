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
    cout << "debug : " << ans << endl;
    for(int i = l-1;i<s.size()/2;i++)
        swap(ans[i],ans[r-i-1]);
    cout << "debug2 : " << ans << endl;
    return ans;
}
string reverseSubstring(string str, int start, int end)
{
    string ans = str;
    while (start < end)
    {
        // Swap characters at start and end indices
        swap(ans[start], ans[end]);
        start++;
        end--;
    }
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
        vi seq(n);
        while(q--)
        {
            int x;cin >> x;
            int index = binSear(l,x);
            int a = min(x,l[index]+r[index]-x);
            int b = max(x,l[index]+r[index]-x);
            // if(a!=b)
            //     ans = revsubstr(ans,a,b);
            seq[a-1]++;
        }
        for(int i=0;i<n;i++)
        {
            if(seq[i]%2==1)
            {
                ans = reverseSubstring(ans,i,n-i-1);
                // cout <<"debug: "<< ans << endl;    
            }
        }
        cout << ans << endl;
    }
    // vi a = {1,2,3,4,5,6,7,8,9,10};
    // cout << binSear(a,1);
}