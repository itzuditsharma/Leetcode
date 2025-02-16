class Solution {
public:
    int f(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || nums[0] == target) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];

        int nottake = f(ind - 1, target, nums, dp);
        int take = 0;
        if(nums[ind] <= target) take = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0; i < n; i++) totalsum += nums[i];

        if(totalsum - target < 0 || (totalsum - target) %2 ==1) return 0;

        int s2 = (totalsum - target)/2;
        vector<vector<int>> dp(n, vector<int>(s2+1, 0));
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if (nums[0] <= s2 && nums[0] != 0) dp[0][nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int tar = 0; tar <= s2; tar++){
                int nottake = dp[i - 1][tar];
                int take = 0;
                if(nums[i] <= tar) take = dp[i-1][tar - nums[i]];

                dp[i][tar] = take + nottake;
            }
        }
        return dp[n-1][s2];
    }
};