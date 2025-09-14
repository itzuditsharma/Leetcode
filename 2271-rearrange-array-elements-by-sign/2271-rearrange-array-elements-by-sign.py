class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        positive = 0
        negative = 1
        ans = [0] * n

        for i in range(n):
            if nums[i] < 0:
                ans[negative] = nums[i]
                negative += 2
            else:
                ans[positive] = nums[i]
                positive += 2
        
        return ans