class Solution {
public:

    int getDivisior(vector<int>& nums, int threshold, int mid){
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i] / (double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;

            int val = getDivisior(nums, threshold, mid);

            if(val <= threshold){   
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};