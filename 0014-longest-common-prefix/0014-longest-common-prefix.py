class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_len = min(len(s) for s in strs)
        sorted_strs = sorted(strs)
        first = sorted_strs[0]
        last = sorted_strs[len(strs) - 1]
        ans = ""


        for i in range(min_len):
            if first[i] == last[i]:
                ans += first[i]
            else:
                break
        
        return ans