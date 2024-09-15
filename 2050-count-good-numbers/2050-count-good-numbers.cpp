const long long mod = 1e9 + 7;
class Solution {
public:
    // x^n
    long long power(long long x, long long n){
        if(n == 0) return 1;
        long long ans = power(x, n / 2);
        ans = (ans * ans) % mod; 

        // if it n is odd, then the number has to be also multiplied individually 
        if(n % 2 == 1){
            ans = (ans * x) % mod;
        }
        // ans = ans % mod;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        return (power(5, even) * power(4,odd)) % mod; 
    }
};