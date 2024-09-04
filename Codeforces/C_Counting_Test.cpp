//https://codeforces.com/gym/101532/problem/D
//https://codeforces.com/group/isP4JMZTix/contest/386415/problem/C

#include<iostream>
#include<vector>
using namespace std;
#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
void print(vector<int>& v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    cout << endl;
}
void print(vector<vector<int>>& v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i].size()>0)
        {
            cout << i << ": ";
            print(v[i]);
        }
    }
    cout << endl;
}

// int ub(vector<int>& v,int x)
// {
//     int st=0;
//     int en=v.size()-1;
//     int ans=-1;
//     while(st<=en)
//     {
//         int mid=st+(en-st)/2;
//         if(v[mid]<=x)
//         {
//             ans=mid;
//             st=mid+1;
//         }
//         else
//             en=mid-1;
//     }
//     return ans+1;
// }


// int n;
// signed main()
// {
//     ios::sync_with_stdio(false); 
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     // int t;scanf("%lld",&t);
//     int t;cin>>t;
//     while(t--)
//     {
//         // scanf("%lld",&n);
//         cin>>n;
//         // int q;scanf("%lld",&q);
//         int q;cin>>q;
//         // string s;scanf("%s",&s);
//         string s;cin>>s;
//         vector<vector<int>> v(26);
//         for(int i=0;i<n;i++)
//         {
//             v[s[i]-'a'].push_back(i+1);
//         }  
//         // print(v);
//         // cout << endl;
//         cout << "c nums l r ans ln rn" << endl;
//         while(q--)
//         {
//             // int l;scanf("%lld",&l);
//             // int r;scanf("%lld",&r);
//             // char c;scanf(" %c",&c);
//             // printf("%lld %lld %c\n",l,r,c);
//             // cout << l << " " << r << " " << c << endl;
//             int l,r;char c;
//             cin>>l>>r>>c;
//             l--;r--;
//             // cout << c<<" " ;
//             // printf("\n%c:",c);
//             // print(v[c-'a']);
//             // cout << endl;
//             int num = (r-l)/n;
//             int count=v[c-'a'].size();
//             int ans = num*count;
//             l%=n;
//             r%=n;
//             int ln = ub(v[c-'a'],l);
//             int rn = ub(v[c-'a'],r+1);
//             cout << c << "  " <<num <<"   "<< l <<" "<<r<< "  " << ans << "   " << ln << "  " << rn << endl;
//             ans+=rn-ln;
//             if(l>=r)
//                 ans+=count;
//             // printf("%lld\n",ans);
//             cout << ans << endl;
//         }
//     }
// }
// tle because mei binary search use kiya hu aur wo t*(n+q*logn) hai
// aur hamko t*(n+q) chahiye


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;cin>>q;
        string s;cin>>s;

        vector<vector<int>> v;
        vector<int> temp(26,0);
        for(int i=0;i<n;i++)
        {
            temp[s[i]-'a']++;
            v.push_back(temp);   
        }
        // print(v);
        while(q--)
        {
            int l,r;char c;
            cin>>l>>r>>c;
            l--;r--;
            int num = (r-l)/n;
            int ans = num*v[n-1][c-'a'];
            l%=n;
            r%=n;
            // cout << l << " " << r << " " << c << endl;
            if(l==0)
                ans+=v[r][c-'a'];
            else
                ans+=v[r][c-'a']-v[l-1][c-'a'];
            if(l>r)
                ans+=v[n-1][c-'a'];
            cout << ans << endl;
        }

        // vector<vector<int>> v (26,vector<int>(n,0));
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < 26 ; j++){
        //         v[j][i] += s[i] == (j + 'a');
        //         if (i > 0) v[j][i] += v[j][i - 1];
        //     }
        // }
        // print(v);

        // while(q--)
        // {
        //     int l,r;char c;
        //     cin>>l>>r>>c;
        //     l--;r--;
        //     int num = (r-l)/n;
        //     int ans = num*v[c-'a'][n-1];
        //     l%=n;
        //     r%=n;
        //     cout << l << " " << r << " " << c <<" "<< ans <<endl;
        //     ans+=v[c-'a'][r]-((l==0) ? 0 : v[c-'a'][l-1]);
        //     if(l>=r)
        //         ans+=v[c-'a'][n-1];
        //     cout << ans << endl;
        // }

    }
}