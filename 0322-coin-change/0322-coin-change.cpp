class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(ind == 0){
            int number = amount % coins[ind];
            if(number == 0) return amount / coins[ind];
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int nottake = 0 + f(ind -1, amount, coins, dp);
        int take = INT_MAX;
        if(amount >= coins[ind]) take = 1 + f(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = min(take, nottake);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans =  f(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};