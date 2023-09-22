// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/C?source=facebook
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
// void print(vi v)
// {
//     for(int i=0;i<v.size();i++)
//         cout << v[i] << ' ';
//     cout << endl;
// }
// void print(vii v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         cout << i << ' ';
//         print(v[i]);
//     }
// }
// signed main()
// {
//     IOS
//     int t;cin >> t;
//     for(int i=1;i<=t;i++)
//     {
//         int n;cin >> n;
//         vi a(2*n-1);
//         for(int i=0;i<2*n-1;i++)
//             cin >> a[i];
        

//         sort(all(a));


//         int x=0,y=2*n-2;
//         int sum = a[x]+a[y];
//         // print(a);
//         while(a[x]+a[y]==sum && x<y)
//         {
//             x++;
//             y--;
//         }
//         // cout <<"sum " << sum << endl;
//         cout << x << ' ' << y << endl;
//         cout<<"Case #"<<i<<": ";
//         if(x==y)
//             cout << sum - a[n-1] << endl;
//         else if(a[x]+a[y-1] ==sum)
//             cout << sum - a[y] << endl;
//         else 
//             cout << sum - a[x] << endl;

//         // 1 2 3 5 6
        
//     }
// }
// // 7 7 7