import numpy as np
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        distances = []
        for x in points:
            first = x[0]
            second = x[1]
            distance = (first**2 + second**2)**(1/2)
            distances.append((x, distance))

        distances.sort(key = lambda x:x[1])
        return [point for point, distance in distances[:k]]