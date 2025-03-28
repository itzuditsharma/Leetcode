class Solution {
public:
    int LCS(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp){
        if(i1 == 0 || i2 == 0) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s1[i1-1] == s2[i2-1]){
            return dp[i1][i2] = 1 + LCS(i1 -1, i2 -1, s1, s2, dp);
        }

        return dp[i1][i2] = max(LCS(i1 -1, i2, s1, s2, dp), LCS(i1, i2-1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        int n = s.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return LCS(n, m, s, s2, dp);
    }
};