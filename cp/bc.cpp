#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the minimum number of flowers and flowers per temple
pair<long long, long long> calculateFlowers(int N, int K, int M) {
    long long totalFlowers = ((1 - (long long)pow(K, N)) / (1 - K)) % M;
    long long initialFlowers = totalFlowers % M;
    long long flowersPerTemple = initialFlowers / N;
    return {initialFlowers, flowersPerTemple};
}

int main() {
    int T;
    cin >> T;
    while (T--) 
    {
        int N, K, M;
        cin >> N >> K >> M;

        // Calculate and print results
        pair<long long, long long> result = calculateFlowers(N, K, M);
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}
