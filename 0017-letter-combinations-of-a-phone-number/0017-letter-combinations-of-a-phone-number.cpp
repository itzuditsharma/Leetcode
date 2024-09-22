class Solution {
public:

    void recur(int i, string temp, string digits, vector<string>&ans, unordered_map<char, string>mapp){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        string str = mapp[digits[i]];
        for(int j = 0; j < str.size(); j++){
            temp.push_back(str[j]);
            recur(i+1, temp, digits, ans, mapp);
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
        recur(0, "", digits, ans, mapp);
        return ans;
    }
};