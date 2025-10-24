class Solution:
    def helper(self, i, n, nums, ans, ds):
        if i == n:
            ans.append(ds.copy())
            return
        
        ds.append(nums[i])
        self.helper(i+1, n, nums, ans, ds)
        ds.pop()
        self.helper(i+1, n, nums, ans, ds)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        ds = []
        n = len(nums)

        self.helper(0, n, nums, ans, ds)
        return ans