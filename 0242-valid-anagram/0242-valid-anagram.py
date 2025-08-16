class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        one = Counter(s)
        two = Counter(t)
        return one == two