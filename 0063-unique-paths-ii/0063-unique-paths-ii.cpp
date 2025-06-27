class Solution {
public:
    int noOfPaths(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i >= 0 && j >=0 && obstacleGrid[i][j] == 1) return 0;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int top = noOfPaths(i-1, j, obstacleGrid, dp);
        int left = noOfPaths(i, j-1, obstacleGrid, dp);

        return dp[i][j] = top + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return noOfPaths(m-1, n-1, obstacleGrid, dp);
    }
};