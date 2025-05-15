class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int capacity){
        int sum = 0;
        int numdays = 1;

        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] <= capacity){
                sum += weights[i];
            }else{
                numdays++;
                sum = weights[i];
            }
        }

        if(numdays <= days){
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(weights, days, mid) == true){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};