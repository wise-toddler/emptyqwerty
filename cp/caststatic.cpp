#include<bits/stdc++.h>
using namespace std;

void f() {
    static int x = 0;
    cout << x << endl;
    x++;
}

int main() {
    for(int i = 0; i < 10; ++i) {
        f();
    }
}
