class Solution:
    def firstUniqChar(self, s: str) -> int:
        mapp = Counter(s)

        for index, val in enumerate(s):
            if mapp[val] == 1:
                return index

        return -1