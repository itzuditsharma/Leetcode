class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        r = 0
        min_len = 1e9
        hash_array = [0] * 256
        n = len(s)
        m = len(t)
        count = 0
        s_index = -1
        for i in range(m):
            hash_array[ord(t[i])] += 1

        while r < n:
            if hash_array[ord(s[r])] > 0:
                count += 1
            hash_array[ord(s[r])] -= 1

            while count == m:
                if (r-l+1) < min_len:
                    min_len = r-l+1
                    s_index = l
                hash_array[ord(s[l])] += 1
                if hash_array[ord(s[l])] > 0:
                    count -= 1
                l+=1

            r+=1
        if s_index == -1:
            return ""
        return s[s_index : s_index + min_len]