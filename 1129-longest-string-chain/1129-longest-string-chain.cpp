class Solution {
public:
    bool possible(string &s1, string &s2){
        if(s2.size()+1 != s1.size()) return false;
        int i = 0;
        int j = 0;

        while(i < s1.size()){
            if(j < s2.size() && s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(i == s1.size() && j == s2.size()) return true;
        return false;
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i < n; i++){
            hash[i] = i;
        }
        sort(words.begin(), words.end(), comp);
        int last_index = 0;
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(possible(words[i], words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(maxlen < dp[i]){
                maxlen = dp[i];
                last_index = i;
            }
        }
        return maxlen;;
    }
};