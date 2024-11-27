class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int mapp[26] = {0};
        int maxlen = 0;
        int maxfeq = 0;

        while(j < s.size()){
            mapp[s[j] - 'A']++;
            maxfeq = max(maxfeq, mapp[s[j] - 'A']);
            while(((j-i+1) - maxfeq) > k){
                mapp[s[i] - 'A']--;
                maxfeq = 0;
                for(int i = 0; i < 26; i++){
                    maxfeq = max(maxfeq, mapp[i]);
                }
                i++;
            }

            if(((j-i+1) - maxfeq) <= k){
                maxlen = max(maxlen, j-i+1);
            }
            j++;
        }
        return maxlen;
    }
};