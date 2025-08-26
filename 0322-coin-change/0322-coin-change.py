class Solution:
    def helper(self, ind, amount, coins,dp):
        if ind == 0:
            if amount % coins[ind] == 0:
                return amount // coins[ind]
            return 1e9

        if dp[ind][amount] != -1:
            return dp[ind][amount]

        not_take = self.helper(ind - 1, amount, coins, dp)
        take = 1e9
        if (amount >= coins[ind]):
            take = 1  + self.helper(ind, amount - coins[ind], coins, dp)

        dp[ind][amount] = min(take, not_take)

        return dp[ind][amount]

    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[-1 for _ in range(amount + 1)] for _ in range(n)]
        ans = self.helper(n-1, amount, coins, dp)
        return -1 if ans >= 1e9 else ans