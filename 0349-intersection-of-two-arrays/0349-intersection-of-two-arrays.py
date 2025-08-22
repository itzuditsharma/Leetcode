class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        a = set(nums1)
        b = set(nums2)
        ans = []
        for it in a:
            if it in b:
                ans.append(it)

        return ans