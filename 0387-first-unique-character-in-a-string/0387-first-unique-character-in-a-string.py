class Solution:
    def firstUniqChar(self, s: str) -> int:
        mapp = Counter(s)

        for i, val in enumerate(s):
            if mapp[val] == 1:
                return i
        
        return -1