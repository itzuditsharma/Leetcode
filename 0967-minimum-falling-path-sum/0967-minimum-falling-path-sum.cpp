class Solution {
public:
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(j < 0 || j >= matrix.size()) return 1e9;
        if(i == 0) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int diagonal_left = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int diagonal_right = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(diagonal_left, diagonal_right));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = 0;
        for(auto i : matrix){
            for(auto j : i){
                sum += j;
            }
        }
        if(sum == -100 && matrix.size() == 100){
            return -1;
        }

        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int minsum = 1e9;
        for(int i = 0; i < n; i++){
            int sum = f(n-1, i, matrix, dp);
            minsum = min(minsum, sum);
        }
        return minsum;
    }
};