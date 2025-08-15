class Solution:
    def jump(self, nums: List[int]) -> int:
        l = 0
        r = 0
        count = 0
        n = len(nums)
        while r < n-1:
            farthest = 0
            for i in range(l, r+1):
                farthest = max(farthest, nums[i] + 1)
            l = r + 1
            r = farthest
            count+=1
        return count