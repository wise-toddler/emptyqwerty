// https://www.codechef.com/problems/NEWCC
// https://github.com/DhruvPasricha/SST-Competitive-Programming-Club/blob/main/Week-1/Day-3.md
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
