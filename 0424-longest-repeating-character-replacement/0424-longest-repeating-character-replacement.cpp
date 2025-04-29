class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int hash[26] = {0};
        int maxfeq = 0;
        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxfeq = max(maxfeq, hash[s[r] - 'A']);

            while((r-l+1) - maxfeq> k){
                hash[s[l]-'A']--;
                l++;
                maxfeq = 0;
                for(int i = 0; i < 26; i++){
                    maxfeq = max(maxfeq, hash[i]);
                }
            }

            if((r-l+1) - maxfeq <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;

        }
        return maxlen;
    }
};