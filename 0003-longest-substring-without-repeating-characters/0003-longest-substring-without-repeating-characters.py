class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        i = 0
        j = 0
        mapp = {}
        maxlen = 0
        while j < n:
            if s[j] in mapp and mapp[s[j]] >= i:
                i = mapp[s[j]] + 1

            mapp[s[j]] = j
            maxlen = max(j-i+1, maxlen)
            j += 1
        
        return maxlen

                