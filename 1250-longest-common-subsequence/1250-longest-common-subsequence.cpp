class Solution {
public:
    int f(int i1, int i2, string &str1, string &str2, vector<vector<int>> &dp){
        if(i1 == 0 || i2 == 0) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(str1[i1-1] == str2[i2-1]){
            return dp[i1][i2] =  1 + f(i1-1, i2-1, str1, str2, dp);
        }

        return dp[i1][i2] = max(f(i1-1, i2, str1, str2, dp), f(i1, i2-1, str1, str2, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, text1, text2, dp);
    }
};