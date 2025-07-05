class Solution:
    def firstUniqChar(self, s: str) -> int:
        hashmap = Counter(s)
        for i, element in enumerate(s):
            if hashmap[element] == 1:
                return i

        return -1