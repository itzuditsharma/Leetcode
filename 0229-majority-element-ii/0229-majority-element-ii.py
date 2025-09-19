class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        mapp = Counter(nums)
        n = len(nums)
        ans = []
        for val, freq in mapp.items():
            if freq > n/3:
                ans.append(val)
            
        return ans