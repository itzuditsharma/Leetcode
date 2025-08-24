class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        sett = set(nums)
        longest = 0
        count = 0
        for val in sett:
            if val - 1 not in sett:
                x = val
                count = 1

                while x + 1 in sett:
                    x = x + 1
                    count+=1
            
            longest = max(longest, count)
        return longest