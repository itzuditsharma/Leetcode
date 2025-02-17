class Solution {
public:
   

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) dp[0][T] = T / coins[0];
            else dp[0][T] = 1e9;
        }

        for(int i = 1; i < n; i++){
            for(int T = 0; T <= amount; T++){
                int nottake = dp[i-1][T];
                int take = 1e9;
                if(coins[i] <= T) take = 1 + dp[i][T - coins[i]];

                dp[i][T] = min(take, nottake);
            }
        }

        if(dp[n-1][amount] >= 1e9) return -1;
        return dp[n-1][amount];
    }
};