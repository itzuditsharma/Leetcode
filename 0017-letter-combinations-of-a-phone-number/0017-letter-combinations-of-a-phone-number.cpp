class Solution {
public:
    void recur(int i, string temp, string digits, unordered_map<char,string> &mapp, vector<string> &ans){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        string s = mapp[digits[i]];
        for(int j = 0; j < s.size(); j++){
            temp.push_back(s[j]);
            recur(i+1, temp, digits, mapp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {}; 
        unordered_map<char, string> mapp;
        mapp['2'] = "abc";
        mapp['3'] = "def";
        mapp['4'] = "ghi";
        mapp['5'] = "jkl";
        mapp['6'] = "mno";
        mapp['7'] = "pqrs";
        mapp['8'] = "tuv";
        mapp['9'] = "wxyz";

        vector<string> ans;
        recur(0,"", digits, mapp, ans);
        return ans;      
    }
};