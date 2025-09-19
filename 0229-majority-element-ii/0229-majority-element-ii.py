class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        count1 = 0
        count2 = 0
        element1 = -1
        element2 = -1
        n = len(nums)

        for i in range(n):
            if count1 == 0 and nums[i] != element2:
                count1 = 1
                element1 = nums[i]
            elif count2 == 0 and nums[i] != element1:
                count2 = 1
                element2 = nums[i]
            elif nums[i] == element1:
                count1 += 1
            elif nums[i] == element2:
                count2 += 1
            else:
                count1 -= 1
                count2 -= 1
        
        count1 = 0
        count2 = 0

        for i in range(n):
            if nums[i] == element1:
                count1 += 1
            if nums[i] == element2:
                count2 += 1

        ans = []
        mini = (n//3) + 1
        if count1 >= mini:
            ans.append(element1)
        if count2 >= mini:
            ans.append(element2)
        
        return sorted(ans)