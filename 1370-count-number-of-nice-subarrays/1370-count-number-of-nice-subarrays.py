class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        nums = [num % 2 for num in nums]
        # This now boils down to subarray with sum  = k 
        mapp = {}
        mapp[0] = 1
        summ = 0
        count = 0

        for i in range(len(nums)):
            summ += nums[i]
            remain = summ - k
            if remain in mapp:
                count += mapp[remain]

            mapp[summ] = mapp.get(summ, 0) + 1
        
        return count