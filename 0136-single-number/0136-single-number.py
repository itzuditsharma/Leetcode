class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        mapp = Counter(nums)
        for key, val in mapp.items():
            if val == 1:
                return key
        return -1