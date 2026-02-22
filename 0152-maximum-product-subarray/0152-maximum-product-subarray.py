class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        pre = 1
        suf = 1
        max_prod = -1e9
        n = len(nums)

        for i in range(n):
            if pre == 0:
                pre = 1
            if suf == 0:
                suf = 1
            pre*=nums[i]
            suf*=nums[n-i-1]

            max_prod = max(max_prod, max(pre, suf))

        return max_prod
