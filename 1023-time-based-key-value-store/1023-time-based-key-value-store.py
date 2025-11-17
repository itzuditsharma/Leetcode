from collections import defaultdict
class TimeMap:

    def __init__(self):
        self.store = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.store[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.store:
            return ""
        arr = self.store[key]
        low = 0
        high = len(arr) - 1
        ans = ""
        while low <= high:
            mid = (low + high) // 2
            if arr[mid][0] <= timestamp:
                ans = arr[mid][1]
                low = mid + 1
            else:
                high = mid - 1
        
        return ans
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)