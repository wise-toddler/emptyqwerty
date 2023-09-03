// https://www.codechef.com/problems/NEWCC
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int x;cin >> x;
	int y;cin >> y;
	if(x==y)
	    cout << "Same";
	else if(x<y)
	    cout << "Old";
	else
	    cout << "New";
	return 0;
}
