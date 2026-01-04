class Solution:
    def find_first(self, nums, low, high, target):
        ans = len(nums)
        while low <= high:
            mid = (low + high)//2
            if nums[mid] >= target:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans


    def find_last(self, nums, low, high, target):
        ans = len(nums)
        while low <= high:
            mid = (low + high)//2
            if nums[mid] > target:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        lb = self.find_first(nums, 0,n-1, target)
        if lb == n or nums[lb] != target:
            return [-1, -1]
        ub = self.find_last(nums, 0,n-1, target)
        return [lb, ub-1]