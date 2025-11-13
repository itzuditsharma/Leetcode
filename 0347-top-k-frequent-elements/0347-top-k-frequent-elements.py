class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mapp = Counter(nums)
        return [key for key, value in mapp.most_common(k)]
    