class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mapp = {}
        sum = 0
        mapp[0] = 1
        total = 0

        for val in nums:
            sum += val

            remain = sum - k

            if remain in mapp:
                total += mapp[remain]
            
            mapp[sum] = mapp.get(sum, 0) + 1
        
        return total
