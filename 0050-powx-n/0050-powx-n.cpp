class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) {
        // Handle x^INT_MIN as x^(INT_MIN+1) and then divide by x
            return myPow(x, n + 1) / x;
        }

        if(n == 0) return 1.0;

        if(n < 0){
            x = 1 / x;
            n = -n;
        }
        
        double half = myPow(x, n/2);

        if(n % 2 == 0){
            return half * half;
        }else{
            return half * half * x;
        }
    }
};