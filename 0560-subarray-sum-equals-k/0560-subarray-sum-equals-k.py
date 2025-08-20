class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mapp = {}
        summ = 0
        count = 0
        mapp[0] = 1
        n = len(nums)
        for i in range(n):
            summ += nums[i]
            remain = summ - k
            if remain in mapp:
                count += mapp[remain]
            mapp[summ] = mapp.get(summ, 0) + 1
        
        return count
