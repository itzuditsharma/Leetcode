class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = {}

        for i in range(len(nums)):
            remain = target - nums[i]
            if remain in mapp:
                return [mapp[remain], i]
            
            mapp[nums[i]] = i
        
        return []