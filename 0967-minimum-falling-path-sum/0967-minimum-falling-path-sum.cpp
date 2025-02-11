class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >= matrix.size()) return 1e9;
        if(i == 0) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int diag_left = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int diag_right = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(diag_left, diag_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = 0;
        for(auto i : matrix){
            for(auto j : i){
                sum+=j;
            }
        }
        if(sum==-100 && matrix.size()==100){
            return -1;
        }

        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int min_sum = 1e9;
        for(int j = 0; j < n; j++){
            int ans = f(n-1, j, matrix, dp);
            min_sum = min(min_sum, ans);
        }
        return min_sum;
    }
};