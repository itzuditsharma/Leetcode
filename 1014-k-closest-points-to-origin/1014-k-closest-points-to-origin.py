class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distances = []
        for point in points:
            first = point[0]
            second = point[1]
            dis = (first**2 + second**2) * 0.5
            distances.append((dis, point))

        distances.sort()
        return [value for key, value in distances[:k]]
        
