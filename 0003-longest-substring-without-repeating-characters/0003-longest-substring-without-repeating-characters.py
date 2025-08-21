class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        l = 0
        r = 0
        mapp = {}
        maxlen = 0

        while r < n:
            if s[r] in mapp and mapp[s[r]] >= l:
                l = mapp[s[r]] + 1

            mapp[s[r]] = r
            maxlen = max(maxlen, r-l+1)
            r+=1
        
        return maxlen