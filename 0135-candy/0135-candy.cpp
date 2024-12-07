class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int left[n];
        int right[n];
        left[0] = 1;
        right[n-1] = 1;

        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }else{
                left[i] = 1;
            } 
        }

        int sum = max(left[n-1], 1);
        int rit = 1; // (right)
        int curr = 1;

        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                curr = rit + 1;
                rit = curr;
            }else{
                curr = 1;
                rit = curr;
            }
            sum += max(left[i], curr);
        }

        return sum;
    }
};