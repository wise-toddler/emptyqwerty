// https://atcoder.jp/contests/abc320/tasks/abc320_c
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

void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        // cout << i << " : ";
        print(v[i]);
    }
}
// void print(unordered_map<char,vi> v)
// {
//     for(auto i:v)
//     {
//         // cout << i << " : ";
//         print(i);
//     }
// }
signed main()
{
    IOS
    int m ;
    cin>>m;
    // m=10;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    // s1="5432146787";
    // s2="1234567890";
    // s3="1234567890";
    // unordered_map<char,vi> mp1,mp2,mp3;
    vii mp1(10),mp2(10),mp3(10);

    for(int i = 0;i<m;i++)
    {
        mp1[s1[i]-'0'].pb(i);
        mp2[s2[i]-'0'].pb(i);
        mp3[s3[i]-'0'].pb(i);
    }
    int min = INT_MAX,g=0;
    for(int i=0;i<10;i++)
    {
        if(!mp1[i].size() || !mp2[i].size() || !mp3[i].size())
            continue;

        if(mp1[i].size()==1)
        {
            mp1[i].pb(m+mp1[i][0]);
            mp1[i].pb(2*m+mp1[i][0]);
        }
        if(mp2[i].size()==1)
        {
            mp2[i].pb(m+mp2[i][0]);
            mp2[i].pb(2*m+mp2[i][0]);
        }
        if(mp3[i].size()==1)
        {
            mp3[i].pb(m+mp3[i][0]);
            mp3[i].pb(2*m+mp3[i][0]);
        }
        if(mp1[i].size()==2)
        {
            mp1[i].pb(m+mp1[i][0]);
        }
        if(mp2[i].size()==2)
        {
            mp2[i].pb(m+mp2[i][0]);
        }
        if(mp3[i].size()==2)
        {
            mp3[i].pb(m+mp3[i][0]);
        }

        vii a={mp1[i],mp2[i],mp3[i]};
        sort(all(a));
        // cout << i << " : "<< endl;
        // print(a);
        for(int i = 0 ;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(a[0][i]==a[1][j] || a[1][j]==a[2][k] || a[2][k]==a[0][i])
                        continue;
                    
                    int m = max(a[0][i],max(a[1][j],a[2][k]));
                    if(m<min)
                    {
                        min = m;
                        g=1;
                    }
                }                
            }
        }

    }
    if(g==0)
        cout << -1 << endl;
    else
        cout <<min<< endl;
}
