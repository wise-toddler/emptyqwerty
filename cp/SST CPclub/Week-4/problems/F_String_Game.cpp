// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.enad()

void print(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}

bool isSeqAvailable(string s,string p,int till,vi seq)
{
    for(int i=0;i<till;i++)
        s[seq[i]-1]='#';

    // cout << s << endl;
    int n = s.size();

    int m = p.size();
    int i=0,j=0;
    while( i < n && j<m)
    {
        if(s[i]==p[j]) j++;
        i++;
    }
    return j==m;
}

signed main()
{
    IOS
    string s;cin>>s;
    string p;cin>>p;
    int n= s.size();
    vi seq(n);
    for(int i=0;i<n;i++) cin >> seq[i];
    vector<string> steps(n+1);
    // string temp=s,temp2=s;
    // print(steps);
    // steps[0] = s;
    // int e=8;
    // for(int i=0;i<n;i++)
    // {
    //     temp[seq[i]-1] = '#';
    //     steps[i+1] = temp;
    //     // if(i==e)
    //     // {
    //     //     if( isSeqAvailable(temp,p)) 
    //     //         break;
    //     //     e*=2;
    //     // }
    // }
    // // int l=0,e=1,r=n;
    // // while()
    // // {
    // //     pak
    // //     while(1)
    // //     {
    // //         temp2 = temp1;
    // //         for(int i =0;i<e;i++)
    // //             temp2[seq[l+e]-1]='#';
    // //         if(!isSeqAvailable(temp2,p))
    // //             break;
    // //         temp1=temp2;
    // //         l+=e;
    // //         e*=2;
    // //     }

    // // }
    

    int st=0,en=n;
    int ans=0; 
    while(st<=en)
    {
        int mid = (st+en)/2;
        if(isSeqAvailable(s,p,mid,seq)) 
        {
            ans=mid;
            st=mid+1;
        }
        else
            en=mid-1;
        
    }
    cout << ans << endl;
}