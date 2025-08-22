class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mapp = Counter(nums)
        return [first for first, second in mapp.most_common(k)]