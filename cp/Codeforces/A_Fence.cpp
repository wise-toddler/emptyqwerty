// https://codeforces.com/group/isP4JMZTix/contest/386415/problem/A
#include<iostream>
#include<vector>
#define int long long int
using namespace std;
signed main()
{
    int n;cin>>n;
    int k;cin>>k;
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<k;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    int min = sum;
    int index=1;

    for(int i=k;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i]-v[i-k];
        if(sum<min)
        {
            index=i-k+2;
            min=sum;
        }
    }
    cout << index << endl;
}