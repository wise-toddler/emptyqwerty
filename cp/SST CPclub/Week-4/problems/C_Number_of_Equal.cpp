// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C
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
signed main(){
    IOS
    int n,m;cin >> n >> m;
    // map<int,int > mp;
    // for(int i =0;i<n;i++)
    // {
    //     int x;cin >> x;
    //     mp[x]++;
    // }
       // int ans=0;
    // for(int i=0;i<m;i++)
    // {
    //     int x;cin >> x;
    //     ans+=mp[x];
    // }
    // cout << ans << endl;

    // two pointer approach
    // vi a(n),b(m);
    // for(int i =0;i<n;i++)cin >> a[i];
    // for(int i =0;i<m;i++)cin >> b[i];
    // // a.pb(INT_MAX/
    // int i=0,j=0;
    // int ans=0;
    // int an=0;
    // int bn=0;
    // while(i<n || j<m)
    // {
    //     if(a[i]==b[j])
    //     {
    //         ans++;
    //         i++;
    //         j++;
    //     }
    //     else if(a[i]<b[j])
    //         i++;
    //     else
    //         j++;
        

    // }
    // cout << ans << endl;



    // two pointer approach
    vi a(n);
    for(int i =0;i<n;i++)cin >> a[i];
    int ans=0;
    int x=0,y=0;
    for(int i =0;i<m;i++)
    {
        int b;cin >> b;
        while(x<n && a[x]<b)x++;
        while(y<n && a[y]<=b)y++;
        ans+=y-x;
    }
    cout << ans << endl;
}

// dict = {1:"January",2:"February",3:"March",4:"April",5:"May",6:"June",7:"July",8:"August",9:"September",10:"Octomber",11:"November",12:"December"}
