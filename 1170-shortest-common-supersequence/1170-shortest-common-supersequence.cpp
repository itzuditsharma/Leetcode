class Solution {
public:
    int LCS(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(str1[i-1] == str2[j-1]){
            return dp[i][j] = 1 + LCS(i-1, j-1, str1, str2, dp);
        }

        return dp[i][j] = max(LCS(i-1, j, str1, str2, dp), LCS(i, j-1, str1, str2, dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int lcs = LCS(n, m, str1, str2, dp);

        int i = n;
        int j = m;
        string ans = "";

        while(i >0 && j >0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }else{
                ans += str2[j-1];
                j--;
            }
        }

        while(i > 0){
            ans += str1[i-1];
            i--;
        }

        while(j >0 ){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};