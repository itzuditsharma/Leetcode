class Solution {
public:
    int f(int i, int j, int n, vector<int>&cuts, vector<vector<int>> &dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int ind = i; ind <=j; ind++){
            int cost = cuts[j+1] - cuts[i-1] + f(i, ind - 1, n, cuts, dp) + f(ind+1, j, n, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return f(1, c, n, cuts, dp); 
    }
};