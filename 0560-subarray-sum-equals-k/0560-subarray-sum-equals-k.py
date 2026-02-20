class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mapp = defaultdict(int)
        summ = 0
        mapp[0] = 1
        ans = 0

        for i in range(len(nums)):
            summ += nums[i]

            remain = summ - k
            if remain in mapp:
                ans += mapp[remain]
            
            mapp[summ] += 1
        
        return ans