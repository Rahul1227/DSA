class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> primes(n, true);

        // Only iterate over odd numbers
        for (long long i = 3; i * i < n; i += 2) {
            if (primes[i]) {
                // Step by 2*i to skip even multiples (3*3=9 -> +6 -> 15 -> +6 -> 21)
                for (long long j = i * i; j < n; j += 2 * i) {
                    primes[j] = false;
                }
            }
        }

        int count = 1; // Count 2
        for (int i = 3; i < n; i += 2) {
            if (primes[i]) count++;
        }

        return count;
    }
};