class Solution:
    def helper(self, ind, nums, ds, ans):
        if ind == len(nums):
            ans.append(ds[:])
            return

        ds.append(nums[ind])
        self.helper(ind + 1, nums, ds, ans)
        ds.pop()
        self.helper(ind + 1, nums, ds, ans)
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        ds = []
        self.helper(0, nums, ds, ans)
        return ans