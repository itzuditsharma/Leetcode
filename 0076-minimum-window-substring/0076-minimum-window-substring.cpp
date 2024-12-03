class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int s_index = -1;
        int n = s.size();
        int m = t.size();
        int count = 0;
        int hash[256] = {0};
        for(int i = 0; i < t.size(); i++){
            hash[t[i]]++;
        }

        while(r < n){
            if(hash[s[r]] > 0) count++;
            hash[s[r]]--;
            
            while(count == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    s_index = l;
                }

                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        if(s_index == - 1) return "";
        else return s.substr(s_index, minlen);
    }
};