class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pos = 0
        neg = 1
        ans = [0] * n

        for i in range(n):
            if nums[i] > 0:
                ans[pos] = nums[i]
                pos+=2
            if nums[i] < 0:
                ans[neg] = nums[i]
                neg += 2
        
        return ans