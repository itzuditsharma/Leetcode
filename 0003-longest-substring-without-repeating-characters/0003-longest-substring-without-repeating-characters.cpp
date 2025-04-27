class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        if(s.size()==0) return 0;
        unordered_map<char, int> mapp;
        int maxx = 1;
        while(j < s.size()){
            if(mapp.find(s[j]) != mapp.end() && mapp[s[j]] >= i){
                i = mapp[s[j]]+1;
            }

            mapp[s[j]] = j;
            maxx = max(maxx, j-i+1);
            j++;
        }
        return maxx;
    }
};