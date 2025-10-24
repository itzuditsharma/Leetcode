class Solution:
    def beautySum(self, s: str) -> int:
        ans = 0
        n = len(s)
        for i in range(n):
            mapp = {}
            for j in range(i, n):
                mapp[s[j]] = mapp.get(s[j], 0) + 1
                min_freq = 1e9
                max_freq = -1e9
                for key, value in mapp.items():
                    max_freq = max(max_freq, value)
                    min_freq = min(min_freq, value)

                ans += max_freq - min_freq
        
        return ans
