class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mapp = {}
        mapp[0] = 1
        total = 0
        sum = 0
        for i in nums:
            sum += i
            remain = sum - k

            if remain in mapp:
                total += mapp[remain]
            
            mapp[sum] = mapp.get(sum, 0) + 1
        
        return total