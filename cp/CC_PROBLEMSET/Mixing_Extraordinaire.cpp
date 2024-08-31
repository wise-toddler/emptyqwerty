// https://www.codechef.com/problems/MIX2
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t;cin >> t;
	while(t--)
	{
        int n; cin >> n;
        if(n==1)
        {
            int p;cin >> p;
            std::cout << p << std::endl;
            continue;
        }
        vector<long long> v((n*(n-1))/2);
        for (int i = 0; i < n; i++) 
            cin >> v[i];
        long long int a=0;
        for (int i = 0; i < n; i++) 
	        for (int j = i+1; j < n; j++) 
	            a+=v[i]*v[j];
	        
	    std::cout << a << std::endl;
	}
	return 0;
}