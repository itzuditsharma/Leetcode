class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pairs = []
        for i, val in enumerate(nums):
            pairs.append((val, i))
        
        pairs.sort(key = lambda x : x[0])

        i = 0
        j = len(pairs) - 1

        # (2,0)(7,1)(11, 2)(15, 3)

        while i < j:
            sum = pairs[i][0] + pairs[j][0]
            if sum == target:
                return [pairs[i][1], pairs[j][1]]
            elif sum > target:
                j-=1 
            else:
                i+=1

        return []
