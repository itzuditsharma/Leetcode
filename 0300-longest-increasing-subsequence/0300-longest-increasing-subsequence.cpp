class Solution {
public:
    int LIS(int ind, int prev_ind, int n, vector<int>& nums, vector<vector<int>> &dp){
        if(ind == n) return 0;
        
        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        // not take 
        int len = LIS(ind+1, prev_ind, n, nums, dp);
        // take 
        if(prev_ind == -1 || nums[prev_ind] < nums[ind]){
            len = max(len, 1 + LIS(ind+1, ind, n, nums, dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return LIS(0, -1, n, nums, dp);
    }
};