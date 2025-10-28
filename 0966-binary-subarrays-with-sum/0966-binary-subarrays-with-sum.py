class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        summ = 0
        mapp = defaultdict(int)
        mapp[0] = 1 
        count = 0

        for i in range(len(nums)):
            summ += nums[i]
            remain = summ - goal
            if remain in mapp:
                count += mapp[remain]
            
            mapp[summ] = mapp[summ] + 1
        
        return count