class Solution {
public:

    void recur(string st, int open, int closed, int n, vector<string> &ans){
        if(open == n && closed == n){
            ans.push_back(st);
            return;
        }


        if(open < n){
            recur(st+'(', open+1, closed, n , ans);
        }

        if(closed < open){
            recur(st+')', open, closed+1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur("", 0, 0, n, ans);
        return ans;
    }
};