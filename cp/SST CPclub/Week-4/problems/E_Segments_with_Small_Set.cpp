// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/E
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
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    // set<int> s;
    map<int,int> mp; // frequency map
    int ans =0;
    int j=0;
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(mp[a[i]]==0) // agar naya element nhi h toh ab unique element bardd gye
            x++;

        mp[a[i]]++; // element ka frequency badha diya
        while( x>k )
        {
            mp[a[j]]--;
            if(mp[a[j]]==0) // agar element khatam ho gya toh unique element kam ho gye
                x--;
            j++;
        }
        ans+= i-j+1; // i-j+1 is the number of segments ending at i
    }
    cout<<ans<<endl;
}