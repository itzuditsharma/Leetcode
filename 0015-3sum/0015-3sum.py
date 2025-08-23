class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        n = len(nums)
        for i in range(n):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            j=i+1
            k=n-1

            while j < k:
                summ = nums[i] + nums[j] + nums[k]
                if summ == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                    j+=1
                    k-=1
                    while j < k and nums[j] == nums[j-1]:
                        j+=1
                    while k > j and nums[k] == nums[k+1]:
                        k-=1
                elif summ > 0:
                    k-=1
                else:
                    j+=1
                
        return ans
                            