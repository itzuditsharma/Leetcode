class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        sorted_freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
        ans = ""
        for char, value in sorted_freq:
            ans += char * value
        return ans
