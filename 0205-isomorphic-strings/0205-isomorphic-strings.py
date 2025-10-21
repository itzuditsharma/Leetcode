class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapp1 = {}
        mapp2 = {}

        n = len(s)
        m = len(t)

        if n != m:
            return False

        i = 0
        j = 0

        while i < n and j < m:
            if s[i] in mapp1 and mapp1[s[i]] != t[j]:
                return False
            if t[j] in mapp2 and mapp2[t[j]] != s[i]:
                return False

            mapp1[s[i]] = t[j]
            mapp2[t[j]] = s[i]

            i += 1
            j += 1
        
        return True