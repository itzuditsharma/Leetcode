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

        vector<int> prev(m, 0);
        
        for(int j = 0; j < m; j++){
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++){
                int up = matrix[i][j] + prev[j];

                int diag_left = matrix[i][j];
                if(j-1 >= 0) diag_left += prev[j-1];
                else diag_left += 1e9;

                int diag_right = matrix[i][j];
                if(j+1 < m) diag_right += prev[j+1];
                else diag_right += 1e9;

                curr[j] = min(up, min(diag_left, diag_right));
            }
            prev = curr;

        }

        int min_sum = 1e9;
        for(int j = 0; j < m; j++){
            min_sum = min(min_sum, prev[j]);
        }
        return min_sum;
    }
};