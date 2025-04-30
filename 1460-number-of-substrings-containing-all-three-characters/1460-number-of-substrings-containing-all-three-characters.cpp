class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int hash[3] = {0};
        int count = 0;
        int n = s.size();
        while(r < n){
            hash[s[r] - 'a']++;
            while(hash[0] != 0 && hash[1]!=0 && hash[2] != 0){
                count += n-r;
                hash[s[l] - 'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};