class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = {}

        for i, val in enumerate(nums):
            remain = target - val
            if mapp.get(remain) is not None:
                return [mapp[remain], i]
            mapp[val] = i
            
        return []