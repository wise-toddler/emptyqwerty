// // https://codeforces.com/group/isP4JMZTix/contest/392597/problem/F
#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define endl '\n'
// #define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// #define vi vector<int>
// #define vii vector<vector<int>>
// #define pb push_back
// #define pii pair<int,int>
// #define all(x) x.begin(),x.end()
// signed main()
// {
//     IOS
//     int t;cin >> t;
//     while(t--)
//     {
//         int n;cin >> n;
//         vi a;
//         for(int i=0;i<n;i++)
//         {
//             int x;cin >> x;
//             a.pb(x);
//         }
//         sort(all(a));
//         int k = 0;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i] <= k)
//             {
//                 continue;
//             }
//             k++;
//         }
//         cout << k << endl;
//     }
//     return 0;
// }
void print(int a[],int b,int n) 
{
    for(int i=b;i<n;i++)
        cout << a[i] << ' ';
    cout << endl;
}

// int main() 
// {
//     multiset<int> st;

//     st.insert(1);
//     st.insert(1);
//     st.insert(2);


//     for(auto it : st) {
//         cout << it << endl;
//     }

    // st.erase(st.find(1)); // this will erase only single 1
 
    // st.erase(1); // this will erase all 1's

    // cout << st.size() << endl;

    // return 0;

    // auto it = st.find(2);


    // set             -> Balanced BST
    // multiset        -> Balanced BST + allows duplicates


    // ordered_set     -> Red Black Trees
    //                 -> how many elements are smaller than x?


    // unordered_set   -> HashSet (Uses Hashing) // never use in CP



signed main()
{
    int t;
    cin >> t;
    // t=1;
    // b:
    while (t--) 
    {
        int n, ans=0;
        cin >> n;


        // int a[n];
        // for(int i=0; i<n; i++)
        //     cin >> a[i];
        // sort(a,a+n);
        // // print(a,0,n);
        // int o=-1;
        // for(ans=(n-1)/2;ans>=0;ans--)
        // {
        //     for(int i=0; i<=ans;i++)
        //     {
        //         // cout << a[i+ans] << ' ' << i+1 << endl;
        //         if( a[i+ans] <= i+1 )
        //         {
        //             o = ans;
        //             goto l;
        //         }
        //     }
        // }
        // l:
        // cout <<o+1<< endl;
        // cout << ans << endl<<endl;
    
        // // @ 1 1 1 2 3
        // //       ^ans 
 
 
        // int a[n+1];
        // for(int i=1; i<=n; i++)
        //     cin >> a[i];
        // sort(a+1,a+n+1);
        // // print(a,1,n+1);
        // for(ans=n; ans>0 ;ans--)
        // {
        //     int f=1;
        //     for(int i=1;i<=ans&&f;i++)
        //     {
        //         // cout << a[i+ans-1] << ' ' << i << endl;
        //         if(a[i+ans-1]>i)
        //             f=0;                                                                
        //     }
        //     if(f)
        //         break;
        // }
        // cout << "k = " <<ans<< endl<<endl;
        int a[n + 1];
        for(int i=1; i<=n; i++)
            cin >> a[i];

        auto good = [&](int ans) {
            int f=1;
            for(int i=1;i<=ans&&f;i++)
            {
                // cout << a[i+ans-1] << ' ' << i << endl;
                if(a[i+ans-1]>i)
                    f=0;                                                                
            }
            return f;
        };
    
        sort(a + 1,a + n + 1);
        int st=1,en=n;
        ans = 0;
        bool flag = false;
        while(st<=en)
        {
            int mid = (st+en)/2;
            if(good(mid))
            {
                flag = 1;
                ans = mid;
                st = mid+1;
            }
            else 
            {
                en = mid-1;
            }
        }

        cout << ans << endl;
    }
}


// int f(int a[],int mid,int k)
// {
//     int ans = 1;
//     for(int i=0;i<mid;i++)
//     {
//         // if(a[i+mid-] <= k)
//         {
//             ans++;
//             k++;
//         }
//     }
//     return ans;
// }

/*

1 1 2 
1 1
2 2
k = 2

4 4 4 4 
4 1
4 1
k = 0

1 
1 1
k = 1

1 1 1 2 3 
1 1
2 2
3 3
k = 3


1 1 2 
1 0
k = 2
1
4 4 4 4 
4 0
k = 3
2
1 
k = 0
-1
1 1 1 2 3 
1 0
k = 3
2
*/



// st.lower_bound(2) -> O(log N)

// lower_bound(st.begin(), st.end()); -> O(N) // never use this


// lower_bound(arr.begin(), arr.end()); -> O(N) if array is not sorted
//                                      -> O(log N) if array is sorted

