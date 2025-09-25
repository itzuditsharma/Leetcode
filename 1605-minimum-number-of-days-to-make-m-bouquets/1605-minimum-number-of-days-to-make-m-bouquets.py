class Solution:
    def bouquetsgreaterm(self, bloomDay, day, m, k):
        bouquets = 0
        count = 0
        for i in range(len(bloomDay)):
            if bloomDay[i] <= day:
                count += 1
            else:
                bouquets += count // k
                count = 0
            
        bouquets += count // k
        if bouquets >= m:
            return True
        
        return False

    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        low = min(bloomDay)
        high = max(bloomDay)
        ans = -1

        while low <= high:
            mid = (low + high)//2
            if self.bouquetsgreaterm(bloomDay, mid, m, k) == True:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans