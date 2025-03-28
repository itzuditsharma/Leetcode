class Solution {
public:

    int f(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + f(ind - 2, nums, dp);

        int not_take = 0 + f(ind -1, nums, dp);

        return dp[ind] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> temp1, temp2;

        for(int i = 0; i < n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        int n1 = temp1.size();
        int n2 = temp2.size();
        vector<int> dp1(n1+1, -1);
        vector<int> dp2(n2+1, -1);
        // return max(f(n-2, temp1,dp1), f(n-2, temp2,dp2));
        return max(f(n1-1, temp1,dp1), f(n2-1, temp2,dp2));
    }
};