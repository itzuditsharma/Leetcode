import math
class Solution:
    def getHours(self, piles, hours, h):
        summ = 0
        for i in range(len(piles)):
            summ += math.ceil(piles[i]/hours)
            if summ > h:
                break
        return summ

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low =1
        high = max(piles)

        while low <= high:
            mid = (low + high) // 2
            if self.getHours(piles, mid, h) <= h:
                high = mid - 1
            else:
                low = mid + 1
                
        return low