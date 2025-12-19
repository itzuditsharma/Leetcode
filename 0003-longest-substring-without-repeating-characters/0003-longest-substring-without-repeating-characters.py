class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = j = 0
        n = len(s)
        maxlen = 0
        mapp = {}
        while j < n:
            if s[j] in mapp and mapp[s[j]] >= i:
                i = mapp[s[j]] + 1
            
            mapp[s[j]] = j
            maxlen = max(maxlen, j-i+1)
            j+=1
        
        return maxlen