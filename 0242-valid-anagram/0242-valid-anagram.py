class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        mapp = {}
        for val in s:
            mapp[val] = mapp.get(val, 0) + 1

        for x in t:
            if x not in mapp or mapp[x] == 0:
                return False
            mapp[x] -= 1

        return True 