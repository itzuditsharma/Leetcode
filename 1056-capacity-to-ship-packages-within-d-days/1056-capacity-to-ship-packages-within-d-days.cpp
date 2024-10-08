class Solution {
public:
    int getDays(vector<int>& weights, int mid){
        int sum = 0;
        int days = 1;

        for(int i = 0; i < weights.size(); i++){
            if(weights[i] + sum <= mid){
                sum += weights[i];
            }else{
                days++;
                sum = weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low + high)/2;

            int min_days = getDays(weights, mid);

            if(min_days <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};