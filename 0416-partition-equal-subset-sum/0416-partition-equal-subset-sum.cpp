class Solution {
public:
    // bool f(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
    //     if(target == 0) return true;
    //     if(ind == 0) return (nums[0] == target);

    //     if(dp[ind][target] != -1) return dp[ind][target];

    //     int nottake = f(ind - 1, target, nums, dp);
    //     int take = false;
    //     if(nums[ind] <= target) take = f(ind - 1, target - nums[ind], nums, dp);

    //     return dp[ind][target] = take | nottake;
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum+=nums[i];

        if(sum % 2 == 1) return false;
        int k = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= k) dp[0][nums[0]] = true;

        for(int ind = 1; ind < n; ind++){
            for(int target = 0; target <= k; target++){
                int nottake = dp[ind - 1][target];
                int take = false;
                if(nums[ind] <= target) take = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = take | nottake;
            }
        }
        return dp[n-1][k];
    }
};