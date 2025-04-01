class Solution {
public:
    int f(int ind, vector<int>&nums, vector<int>&dp){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];
        int take = f(ind -2, nums, dp) + nums[ind];
        int nottake = f(ind - 1, nums, dp);

        return dp[ind] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> one;
        vector<int> two;

        for(int i = 0; i < n; i++){
            if(i != n-1) one.push_back(nums[i]);
            if(i != 0) two.push_back(nums[i]);
        }

        int n1 = one.size();
        int n2 = two.size();
        vector<int> dp1(n1+1, -1);
        vector<int> dp2(n2+1, -1);

        return max(f(n1-1, one, dp1), f(n2-1, two, dp2));
    }
};