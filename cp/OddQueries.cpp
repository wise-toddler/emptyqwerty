#include <iostream>
#include "bits/stdc++.h"
#include <vector>

using namespace std;
int main()
{
    int t;cin >> t;
    while(t--)
    {
        int n,t1; cin >> n >> t1;
        vector<long long> v(n);
        cin >> v[0];
        for (long long i = 1; i < n; i++)
        {
            long long a;cin >> a;
            v[i]=a+v[i-1];
        }
        while(t1--)
        {
            int l,r,k;cin>>l>>r>>k;
            if(l!=1 && (v[n-1]%2-v[r-1]%2+v[l-2]%2+(r+1-l)%2*k%2)%2!=0)
                cout <<"YES"<<endl;
            else if(l==1 && (v[n-1]%2-v[r-1]%2+(r+1-l)%2*k%2)%2!=0)
                cout <<"YES"<<endl;
            else 
                cout <<"NO"<<endl;
            // cout << v [n-1]<<endl;
            // cout << v [r-1]<<endl;
            // cout << v [l-2]<<endl;
            // cout << (r+1-l)*k <<endl;
        }
    }
}
// v [n-1] -v [r-1]+v[l-1] +(r+1-l)*k