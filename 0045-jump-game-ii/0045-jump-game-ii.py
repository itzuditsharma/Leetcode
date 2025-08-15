class Solution:
    def solve(self, ind, nums, dp, n):
        if ind >= n-1:
            return 0
            
        if dp[ind] != -1:
            return dp[ind]

        mini = 1e9
        for i in range(1, nums[ind] + 1):
            jumps = 1 + self.solve(ind + i, nums, dp, n)
            mini = min(mini, jumps)
        
        dp[ind] = mini
        return dp[ind]


    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        return self.solve(0, nums, dp, n)