class Solution {
public:

    void recur(int n, string temp, int open, int closed, vector<string>&ans){
        if(open == n && closed == n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            recur(n, temp, open+1, closed, ans);
            temp.pop_back();
        }

        if(open > closed){
            temp.push_back(')');
            recur(n, temp, open, closed+1, ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recur(n, "",0,0, ans);
        return ans;
    }
};