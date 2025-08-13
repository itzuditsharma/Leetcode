class Solution:
    def frequencySort(self, s: str) -> str:
        X = Counter(s)
        sorted_items = sorted(X.items(), key = lambda x: x[1], reverse = True)
        ans = ""

        for key, value in sorted_items:
            ans += key * value
        return ans


