class Solution {
public:
    bool f(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >=0 ) return false;
        if(i >= 0 && j < 0){
            for(int it = 0; it <= i; it++){
                if(p[it] != '*') return false;
                j--;
            }
            return true;
        }


        if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = f(i-1, j-1, p, s, dp);
        }

        if(p[i] == '*'){
            return dp[i][j] = f(i-1, j, p, s, dp) | f(i, j-1, p, s, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, p, s, dp);
    }
};