class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        sorted_strs = sorted(strs)
        min_len = len(sorted_strs[0])
        ans = ""
        smallest = sorted_strs[0]
        n=len(sorted_strs)
        largest = sorted_strs[n-1]
        for i in range(min_len):
            if smallest[i] != largest[i]:
                break
            ans += smallest[i]
        return ans
