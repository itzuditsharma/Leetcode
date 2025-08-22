class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distances = []
        for point in points:
            first = point[0]
            second = point[1]
            distance = (first**2 + second**2) * (0.5)
            distances.append((point, distance))

        distances.sort(key = lambda x : x[1])
        return [first for first, second in distances[:k]]