// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-4.md
// https://www.codingninjas.com/studio/problems/equilibrium-index_893014
#include <bits/stdc++.h> 
int findEquilibriumIndex(vector<int>& a) {
    // Write your code here.
    // int t;cin >> t;
    // while(t--)
    // {
    //     int n;cin >> n;

    //     vector<int> a(n);
    //     for(int i =0;i<n;i++)
    //         cin >> a[i];
        int n = a.size();
        vector<int> b(n);
            b[0]=a[0];
        for(int i =1;i<n;i++)
            b[i]=b[i-1]+a[i];
        
        vector<int> c(n);
        c[n-1]=a[n-1];
        for(int i =n-2;i>=0;i--)
            c[i]=c[i+1]+a[i];

        // bool flag=false;
        for(int i =0;i<n;i++)
            if(b[i]==c[i])
                return i;
            // {
            //     flag=true;
            //     cout << i << endl;
            //     break;
            // }
        // if(!flag)
        //     cout << -1 <<endl; 
        return -1;
}