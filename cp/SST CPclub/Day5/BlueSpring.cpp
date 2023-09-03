// https://atcoder.jp/contests/abc318/tasks/abc318_c
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-3.md
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    long long int n,d,p;cin >> n >> d >> p;
    vector<int> v(n);
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        sum+=v[i]; 
    }
    sort(v.begin(),v.end(),greater<int>());

    long long int x=0;
    long long int y=0;
    for(int i=0;i<n;i+=d)
    {
        long long int ans=0;
        for(int j=i;j<i+d && j<n;j++)
            ans+=v[j];
        if(ans>=p)
        {
            y+=ans;
            x++;
        }
        else 
            break;

    }

    cout << sum-y+x*p << endl;
    
    return 0;

}