class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_list = []
        for i,val in enumerate(nums):
            sorted_list.append((val, i))
        
        sorted_list.sort(key = lambda x : x[0])

        i = 0
        j = len(nums) - 1

        while i < j:
            summation = sorted_list[i][0] + sorted_list[j][0]
            if summation == target:
                return [sorted_list[i][1], sorted_list[j][1]]
            elif summation > target:
                j-=1
            else:
                i+=1
        
        return []