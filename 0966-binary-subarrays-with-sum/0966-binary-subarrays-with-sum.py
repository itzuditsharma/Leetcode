class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        sum = 0
        mapp = defaultdict(int)
        mapp[0] = 1
        count = 0

        for num in nums:
            sum += num
            remain = sum - goal
            count += mapp[remain]
            mapp[sum] += 1
        
        return count

        