// // https://www.codechef.com/problems/CONCUSSIVE
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl '\n'
// #define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// #define vi vector<int>
// #define vii vector<vector<int>>
// #define pb push_back
// #define pii pair<int,int>
// #define all(x) x.begin(),x.end()
// void print(vi v)
// {
//     for(int i=0;i<v.size();i++)
//         cout << v[i] << ' ';
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
//     while(t--)
//     {
//         int n;cin >> n;
//         vi a;
//         int m = n;
//         while (m--)
//         {
//             int x;cin >> x;
//             a.pb(x);
//         }
        
//         sort(all(a));
//         vi c;
//         for(int i =0,j=0,k=(n+1)/2,e=0;i<n;i++,e++)
//         {
//             if(e%2==0)
//                 c.pb(a[j++]);
//             else
//                 c.pb(a[k++]);
//         }
//         // print(c);
//         // cout << endl;
//         int index = 0;
//         for(int i=1;i<n-1;i++)
//         {
//             if(!((c[i-1]> c[i] && c[i]< c[i+1]) || (c[i-1] < c[i] && c[i] > c[i+1])))
//             {
//                 index = i;
//                 break;
//             }
//         }
//         if((index != n-2 && index!=0) || (c[n-1]==c[n-2] && c[n-1]==c[0]))
//             goto label;
//         else
//         if(index == n-2)
//         {
//             cout << c[n-1];
//             for(int i=0;i<n-1;i++)
//                 cout <<' '<<c[i];
//         }
//         else 
//         {
//             // cout << "check";
//             print(c);
//         }
//         cout << endl;
//         continue;


//         label:
//         vi b;
//         for(int i = 0,j=0,k=n-1,e=0;i<n;i++,e++)
//         {
//             if(e%2==0)
//                 b.pb(a[j++]);
//             else
//                 b.pb(a[k--]);
//         }
//         index = 0;
//         for(int i=1;i<n-1;i++)
//         {
//             if(!((b[i-1]> b[i] && b[i]< b[i+1]) || (b[i-1] < b[i] && b[i] > b[i+1])))
//             {
//                 index = i;
//                 break;
//             }
//         }
//         if((index != n-2 && index!=0) || (b[n-1]==b[n-2] && b[n-1]==b[0]))
//             cout << -1;
//         else 
//         if(index == n-2)
//         {
//             cout << b[n-1];
//             for(int i=0;i<n-1;i++)
//                 cout <<' '<<b[i];
//         }
//         else 
//             print(b);
    
        
//         cout << endl;
//     }
// }

// // 12
// // 1 1 1 2 2 3 3 3 3 3 3 4