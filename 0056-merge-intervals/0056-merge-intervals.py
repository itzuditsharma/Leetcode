class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals)
        temp_interval = sorted_intervals[0]
        ans = []
        for it in sorted_intervals:
            if it[0] <= temp_interval[1]:
                temp_interval[1] = max(temp_interval[1], it[1])
            else:
                ans.append(temp_interval)
                temp_interval = it

        ans.append(temp_interval)
        return ans 
