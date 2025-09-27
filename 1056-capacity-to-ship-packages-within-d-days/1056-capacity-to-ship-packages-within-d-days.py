class Solution:
    def isPossible(self, weights, capacity, days):
        numdays = 1
        summ = 0
        for i in range(len(weights)):
            if summ + weights[i] <= capacity:
                summ += weights[i]
            else:
                numdays += 1
                summ = weights[i]

        if numdays <= days:
            return True
        
        return False

    def shipWithinDays(self, weights: List[int], days: int) -> int:
        low = max(weights)
        high = sum(weights)

        ans = 0

        while low <= high:
            mid = (low + high) // 2

            if self.isPossible(weights, mid, days) == True:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans
