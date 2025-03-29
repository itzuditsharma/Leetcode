class Solution {
public:
    int min_operations(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = 0 + min_operations(i-1, j-1, word1, word2, dp);
        }

        return dp[i][j] = 1 + min(min_operations(i, j-1, word1, word2, dp), min(min_operations(i-1, j, word1, word2, dp), min_operations(i-1, j-1, word1, word2, dp)));
                                                // Insertion                                    //Deletion                              Replacement
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        return min_operations(n-1, m-1, word1, word2, dp);
    }
};