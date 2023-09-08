// https://www.codechef.com/problems/GCDISCOUNT
#include <iostream>
#include<vector>
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
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
        // cout << i << ' ';
        print(v[i]);
    }
}

int main() 
{
	// your code goes here
	int t;cin >>t;
	while(t--)
	{
	    int n;cin >> n;
	    
        vector<int> v(n);
	    for(int i=0;i<n;i++)
	        cin >> v[i];

        vector<int> d(n);
        for (int i = 0; i < n; i++)
            cin >> d[i];
            
	    vector<int> a(n);
	    a[0]=v[0];
	    for (int i=1;i<n;i++)
	        a[i]=gcd(a[i-1],v[i]);
        // print(a);
	    
	    vector<int> b(n);
        b[n-1]=v[n-1];
	    for(int i=n-2;i>=0;i--)
	        b[i]=gcd(b[i+1],v[i]);
        // print(b);

        int max=a[n-1];
        for(int i =0;i<n;i++)
        {
            int a1;
            if (i==0)
                a1 = gcd(d[i],b[i+1]);
            else if (i==n-1)
                a1 = gcd (d[i],a[i-1]);
            else
                a1 = gcd (gcd (d[i],a[i-1]), b[i+1]);
            
            if(max<a1)
                max=a1;
        }
        cout << max << endl;

	}
	return 0;
}
