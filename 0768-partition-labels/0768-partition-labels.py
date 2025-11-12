class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        mapp = {}
        for i in range(len(s)):
            mapp[s[i]] = i
        
        prev = -1
        ans = []
        maxi = 0
        for i in range(len(s)):
            maxi = max(maxi, mapp[s[i]])
            if i == maxi:
                ans.append(maxi - prev)
                prev = maxi
        
        return ans