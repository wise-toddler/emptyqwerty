#include <iostream>
#include "bits/stdc++.h"
#include <vector>

using namespace std;
int main()
{
    long long n;cin>>n;
    long long t;cin>>t;
    vector<long long> vec(n);
    cin >> vec[0];
    for (long long i = 1; i < n; i++)
    {
        long long a;cin >> a;
        vec[i]=a+vec[i-1];
        // vec[i-1]+cin >> vec[i];
    }
    while(t--)
    {
        long long p,q; cin >>p>>q;
        if(p==1)
            cout << vec[q-1]<<endl;
        else
            cout << vec[q-1]-vec[p-2]<<endl;
    }
}