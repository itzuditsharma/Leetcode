class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxx = 1;
        int i = 0; 
        unordered_map<char, int> mapp;
        if(s.length() == 0) return 0;

        for(int j = 0; j < s.length(); j++){
            if(mapp.find(s[j]) != mapp.end() && mapp[s[j]] >=i){
                i = mapp[s[j]] + 1;
            }
            mapp[s[j]] = j;
            maxx = max(maxx, j - i + 1);
        }
        return maxx;
    }
};