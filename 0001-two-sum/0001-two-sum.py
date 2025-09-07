class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = defaultdict(int)
        for idx, val in enumerate(nums):
            remain = target - val
            if remain in mapp.keys():
                return [mapp[remain], idx]
            mapp[val] = idx
        
        return []