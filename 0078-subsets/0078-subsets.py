class Solution:
    def helper(self, ind, nums, n, ds, ans):
        if ind == n:
            ans.append(ds[:])
            return 
        
        ds.append(nums[ind])
        self.helper(ind + 1, nums, n, ds, ans)
        ds.pop()
        self.helper(ind + 1, nums, n, ds, ans)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        ds = []
        ans = []
        n = len(nums)
        self.helper(0, nums, n, ds, ans)
        return ans