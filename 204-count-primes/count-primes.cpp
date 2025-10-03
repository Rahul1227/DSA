class Solution {
public:
    int countPrimes(int n) {
        // Sieve of Erathonese
        // precompute the prime
        vector<int> primes(n+1, 1);
       

        // logic for the precompute
        for(int i = 2; i*i<n; i++){
            if(primes[i] == 1){
                for(int j = i*i; j<n; j = j + i){
                    primes[j] = 0;
                }
            }
        }
        int result =0;

        for(int i = 2; i< n; i++){
            if(primes[i] == 1){
                result++;
            }

        }

        return result;
        
    }
};