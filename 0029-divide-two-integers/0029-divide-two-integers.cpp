class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend < 0 && divisor > 0) sign = false;
        if(dividend > 0 && divisor < 0) sign = false;

        long ans = 0;
        long num = abs(dividend);
        long den = abs(divisor);

        while(num >= den){
            int count  = 0;
            while(num >= (den<< (count+1))){
                count+=1;
            }

            ans += (1 << count);
            num = num  - (den << count);
        }

        if(ans == (1<<31) && sign){
            return INT_MAX;
        }

        if(ans == (1<<31) && !sign){
            return INT_MIN;
        }

        if(sign) return ans;
        else return -1 * ans;
    }
};