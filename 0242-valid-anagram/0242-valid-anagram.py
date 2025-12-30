class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        mapp = defaultdict(int)

        for i in range(len(s)):
            mapp[s[i]] += 1
        
        for i in range(len(t)):
            if t[i] not in mapp or mapp[t[i]] == 0:
                return False
            mapp[t[i]] -= 1
        return True