class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int s_index = -1;
        int hash[256] = {0};
        int count = 0;
        int minlen = INT_MAX;
        int n = s.size();
        int m = t.size();

        for(int i = 0; i < m; i++){
            hash[t[i]]++;
        }

        while(r < s.size()){
            if(hash[s[r]] > 0) count++;
            hash[s[r]]--;
            while(count == m){
                int lenn = r-l+1;
                if(minlen > lenn){
                    minlen = lenn;
                    s_index = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        if(s_index == -1) return "";
        return s.substr(s_index, minlen);
    }
};