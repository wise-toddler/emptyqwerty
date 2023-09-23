// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
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
// difference between the maximum and minimum elements on this segment is at most k
signed main()
{
    IOS
    int n,k;cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans =0;
    int j=0;
    int x=0;
    map<int,int> mp;                // frequency map
    int mx=0,mn=0;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;                 // element ka frequency badha diya
        mx=mp.rbegin()->first;      // max element
        mn=mp.begin()->first;       // min element
        while(mx-mn>k && j<=i)      // jab tak max-min > k
        {
            mp[a[j]]--;             // element ka frequency kam kr diya
            if(mp[a[j]]==0)         // agar element khatam ho gya toh eraze kar do map se
                mp.erase(a[j]);
            mx=mp.rbegin()->first;  
            mn=mp.begin()->first;   
            j++;
        }
        ans+= i-j+1;                // i-j+1 is the number of segments ending at i
    }    
    cout<<ans<<endl;
}