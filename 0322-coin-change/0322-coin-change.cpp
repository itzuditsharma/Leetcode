class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);

        for(int T = 0; T <= amount; T++){
            if(T % coins[0] == 0) prev[T] = T / coins[0];
            else prev[T] = 1e9;
        }

        for(int i = 1; i < n; i++){
            for(int t = 0; t <= amount; t++){
                int nottake = prev[t];
                int take = INT_MAX;
                if(coins[i] <= t) take = 1 + curr[t-coins[i]];

                curr[t] = min(take, nottake);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9) return -1;
        else return prev[amount];
    }
};