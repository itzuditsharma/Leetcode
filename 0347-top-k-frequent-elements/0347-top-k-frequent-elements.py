class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mapp = Counter(nums)
        ans = []
        mapp = sorted(mapp.items(), key = lambda x : x[1], reverse = True)
        for key, val in mapp:
            ans.append(key)
            k-=1
            if k == 0:
                break

        return ans