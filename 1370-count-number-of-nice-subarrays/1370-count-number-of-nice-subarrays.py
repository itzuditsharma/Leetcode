class Solution:
    def helper(self, nums, k):
        l = 0
        r = 0
        summ = 0
        ans  = 0

        while r < len(nums):
            summ += nums[r] % 2
            while summ > k:
                summ -= nums[l] % 2
                l += 1
            ans += (r-l+1)
            r+=1
        
        return ans


    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        return self.helper(nums, k) - self.helper(nums, k-1)