class Solution:
    def isPossible(self, nums, sub_size):
        count = 1
        summ = 0

        for i in range(len(nums)):
            if summ + nums[i] <= sub_size:
                summ += nums[i]
            else:
                count += 1
                summ = nums[i]

        return count

    def splitArray(self, nums: List[int], k: int) -> int:
        low = max(nums)
        high = sum(nums)
        ans = -1
        n = len(nums)

        while low <= high:
            mid = (low + high) // 2

            if self.isPossible(nums, mid) > k:
                low = mid + 1
            else:
                high = mid - 1
        
        return low