class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        answers = []
        for point in points:
            first = point[0] ** 2
            second = point[1] ** 2
            dis = (first + second) * 0.5
            answers.append((dis, point))

        sorted_answers = sorted(answers, key = lambda x : x[0])
        return [pairs for key, pairs in sorted_answers[0:k]]