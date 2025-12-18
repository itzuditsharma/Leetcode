class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_list = []
        for i, val in enumerate(nums):
            sorted_list.append((val, i))
        
        sorted_list.sort()
        n = len(sorted_list)
        left = 0
        right = n-1

        while left < right:
            summ = sorted_list[left][0] + sorted_list[right][0]
            if summ == target:
                return [sorted_list[left][1], sorted_list[right][1]]
            if summ > target:
                right-=1
            else:
                left+=1
        
        return []