class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        mapp = {}
        for x in s:
            mapp[x] = mapp.get(x, 0) + 1

        for val in t:
            if val not in mapp or mapp[val] == 0:
                return False
            mapp[val] -= 1
        
        return True