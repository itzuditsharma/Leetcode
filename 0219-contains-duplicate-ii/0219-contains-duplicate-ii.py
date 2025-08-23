class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # [(1,0), (2,1), (3, 2), (1, 3)]
        # [(1,0), (1, 3), (2,1), (3, 2)]
        pairs = []
        for key, value in enumerate(nums):
            pairs.append((value, key))
        pairs.sort(key = lambda x : x[0])

        for i in range(len(pairs)-1):
            if pairs[i][0] == pairs[i+1][0] and abs(pairs[i][1] - pairs[i+1][1]) <= k:
                return True
            
        return False

        [(1,0)(1,3)(2,1)(2,4)(3,2)(3,5)]

