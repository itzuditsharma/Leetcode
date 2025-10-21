class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        sorted_freq = sorted(freq.items(), key = lambda x : x[1], reverse = True)
        # print(sorted_freq)
        ans = ""
        for key, value in sorted_freq:
            ans += key * value
        return ans