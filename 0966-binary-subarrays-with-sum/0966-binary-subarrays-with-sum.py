class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        summ = 0
        mapp = {}
        mapp[0] = 1 
        count = 0

        for i in range(len(nums)):
            summ += nums[i]
            remain = summ - goal
            if remain in mapp:
                count += mapp[remain]
            
            mapp[summ] = mapp.get(summ, 0) + 1
        
        return count