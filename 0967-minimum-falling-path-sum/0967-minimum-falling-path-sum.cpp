class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(j < 0 || j >= matrix[0].size()) return 1e9;
        if(i == 0) return matrix[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int diag_left = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int diag_right = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(diag_left, diag_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        
        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = matrix[i][j] + dp[i-1][j];

                int diag_left = matrix[i][j];
                if(j-1 >= 0) diag_left += dp[i-1][j-1];
                else diag_left += 1e9;

                int diag_right = matrix[i][j];
                if(j+1 < m) diag_right += dp[i-1][j+1];
                else diag_right += 1e9;

                dp[i][j] = min(up, min(diag_left, diag_right));
            }
        }

        int min_sum = 1e9;
        for(int j = 0; j < m; j++){
            min_sum = min(min_sum, dp[n-1][j]);
        }
        return min_sum;
    }
};