class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n; i++){
            sum +=nums[i];
        }

        if(sum %2 ==1) return false;
        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        if (nums[0] <= target) dp[0][nums[0]] = true;

        for(int i = 1; i < n; i++){
            for(int tar = 1; tar <= target; tar++){
                bool nottake = dp[i-1][tar];
                bool take = false;

                if(tar >= nums[i]) take = dp[i - 1][tar - nums[i]];

                dp[i][tar] = take |  nottake;
            }
        }
        return dp[n-1][target];
    }
};