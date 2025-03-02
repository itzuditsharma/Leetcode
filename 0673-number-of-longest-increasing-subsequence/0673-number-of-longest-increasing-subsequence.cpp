class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && dp[prev]+1 > dp[i]){
                    dp[i] = 1+dp[prev];
                    cnt[i] = cnt[prev];
                }else if(nums[prev] < nums[i] && dp[prev] + 1 == dp[i]){
                    cnt[i] = cnt[prev] + cnt[i];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) count+= cnt[i];
        }
        return count;
    }
};