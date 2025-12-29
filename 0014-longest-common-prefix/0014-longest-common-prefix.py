class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        strs.sort()
        first = strs[0]
        last = strs[n-1]
        ans = ""
        i=0
        
        while i < len(first):
            if first[i] == last[i]:
                ans += first[i]
                i+=1
            else:
                break
        
        return ans