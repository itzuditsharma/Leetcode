# from collections import defaultdict
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = defaultdict(int)
        for i, val in enumerate(nums):
            remain = target - val
            if remain in mapp:
                return [mapp[remain], i]
            mapp[val] = i
        
        return []