class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        r = 0
        min_len = 1e9
        n = len(s)
        m = len(t)
        count = 0
        hash = [0] * 256
        s_index = -1

        for i in range(m):
            hash[ord(t[i])] +=1
        
        while r < n:
            if hash[ord(s[r])] > 0:
                count += 1
            hash[ord(s[r])] -= 1

            while count == m:
                lenn = r-l+1
                if min_len > lenn:
                    min_len = lenn
                    s_index = l
                
                hash[ord(s[l])] += 1
                if hash[ord(s[l])] > 0:
                    count -= 1
                l+=1

            r+= 1
        
        if s_index == -1:
            return ""
        return s[s_index : s_index + min_len]


