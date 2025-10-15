class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        sorted_strs = sorted(strs)
        smallest = sorted_strs[0]
        min_len = len(smallest)
        largest = sorted_strs[n-1]
        ans = ""
        for i in range(min_len):
            if smallest[i] != largest[i]:
                break
            ans += smallest[i]
        return ans
        