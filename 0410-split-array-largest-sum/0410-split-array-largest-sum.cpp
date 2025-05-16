class Solution {
public:
    int getSubarrays(vector<int>& nums, int k, int maxsum){
        int count = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] + sum <= maxsum){
                sum += nums[i];
            }else{
                count++;
                sum = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while(low <= high){
            int mid = (low+high)/2;
            int subarrays = getSubarrays(nums, k, mid);

            if(subarrays <= k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};