class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        temp_interval = intervals[0]
        ans = []
        for interval in intervals:
            if temp_interval[1] >= interval[0]:
                temp_interval[1] = max(temp_interval[1], interval[1])
            else:
                ans.append(temp_interval)
                temp_interval = interval
        ans.append(temp_interval)
        return ans