class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n;
        if(n < 0) nn = -nn;

        while(nn > 0){
            if(nn&1){
                nn = nn - 1;
                ans = ans * x;
            }else{
                 x = x*x;
                 nn = nn / 2;
            }
        }
        if(n < 0) ans = (double)(1)/ans;
        return ans;
    }
};