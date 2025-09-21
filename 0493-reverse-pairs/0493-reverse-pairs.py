class Solution:
    def merge(self, nums, low, mid, high):
        left = low 
        right = mid + 1
        temp = []
        while left <= mid and right <= high:
            if nums[left] <= nums[right]:
                temp.append(nums[left])
                left += 1
            else:
                temp.append(nums[right])
                right += 1

        while left <= mid:
            temp.append(nums[left])
            left += 1
        
        while right <= high:
            temp.append(nums[right])
            right += 1

        nums[low: high + 1] = temp

    def countPairs(self, nums, low, mid, high):
        count = 0
        left = low
        right = mid + 1

        for i in range(left, mid+1):
            while right <= high and nums[i] > 2 * nums[right]:
                right += 1
            count += (right - (mid + 1))

        return count

    def mergeSort(self, nums, low, high):
        count = 0
        if low >=  high:
            return count
        mid = (low + high) // 2

        count += self.mergeSort(nums, low, mid)
        count += self.mergeSort(nums, mid + 1, high)
        count += self.countPairs(nums, low, mid, high)
        self.merge(nums, low, mid, high)

        return count

    def reversePairs(self, nums: List[int]) -> int:
        n = len(nums)
        return self.mergeSort(nums, 0, n-1)