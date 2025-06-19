class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,j = 0;
        int maxx = 1;
        if(s.size() == 0) return 0;
        int n = s.size();
        unordered_map<char, int> mapp;

        while(j < n){
            if(mapp.find(s[j]) != mapp.end() && mapp[s[j]] >= i){
                i = mapp[s[j]] + 1;
            }

            mapp[s[j]] = j;
            maxx = max(maxx, j-i+1);
            j++;
        } 
        return maxx;
    }
};