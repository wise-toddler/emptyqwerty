#include <iostream>
using namespace std;
int main() {
    long n;
    cin >> n;
    long tsum=(n*n+n)/2;
    long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        sum += num;
    }
    cout << tsum- sum << endl;
    return 0;
}
