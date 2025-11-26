class Solution:
    def helper(self, index, nums, n, ans):
        if index == n:
            ans.append(nums[:])
            return
        
        for i in range(index, n):
            nums[i], nums[index] = nums[index], nums[i]
            self.helper(index + 1, nums, n, ans)
            nums[i], nums[index] = nums[index], nums[i]

    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        self.helper(0, nums, n, ans)
        return ans