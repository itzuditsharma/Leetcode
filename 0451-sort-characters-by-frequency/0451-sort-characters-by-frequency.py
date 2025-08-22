class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        sorted_freq = sorted(freq.items(), key = lambda x : x[1], reverse = True)
        ans = ""
        for s, val in sorted_freq:
            ans += s * val

        return ans