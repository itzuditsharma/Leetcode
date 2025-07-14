class Solution(object):
    def helper(self, n, nums, dp):
        if n < 0:
            return 0
        if n == 0:
            return nums[0]
        if dp[n] != -1:
            return dp[n]

        pick = nums[n] + self.helper(n-2, nums, dp)
        notPick = 0 + self.helper(n-1, nums, dp)

        dp[n] = max(pick, notPick)
        return dp[n]


    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        dp = [-1] * (n+1)
        return self.helper(n-1, nums, dp)
        