class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 0

        for j in range(len(nums)-1):
            if nums[j+1] != nums[j]:
                nums[i+1] = nums[j+1]
                i+=1
        
        return i + 1