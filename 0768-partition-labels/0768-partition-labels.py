class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        mapp = {}
        for i in range(len(s)):
            mapp[s[i]] = i
        
        prev = -1
        ans = []
        max_range = -1e9
        for i in range(len(s)):
            max_range = max(max_range, mapp[s[i]])

            if i == max_range:
                ans.append(i - prev)
                prev = i
        
        return ans