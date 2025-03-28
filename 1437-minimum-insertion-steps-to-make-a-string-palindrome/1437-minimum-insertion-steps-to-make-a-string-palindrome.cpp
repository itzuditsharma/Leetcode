class Solution {
public:
    int LCS(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + LCS(i-1, j-1, s1, s2, dp);
        }

        return dp[i][j] = max(LCS(i-1, j, s1, s2, dp), LCS(i, j-1, s1, s2, dp));
    }

    int minInsertions(string s) {
        int n_ = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        int lcs = LCS(n-1, m-1, s, s2, dp);

        return n_ - lcs;
    }
};