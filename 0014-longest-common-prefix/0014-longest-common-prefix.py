class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        n = len(strs)
        first = strs[0]
        last = strs[n-1]
        first_len = len(first)

        ans = ""
        for i in range(first_len):
            if first[i] != last[i]:
                break
            ans += first[i]
        
        return ans
