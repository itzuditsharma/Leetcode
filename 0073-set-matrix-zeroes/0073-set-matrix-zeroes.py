class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        m = len(matrix[0])

        rows = [0] * n
        cols = [0] * m

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    rows[i] = 1
                    cols[j] = 1

        for i in range(n):
            for j in range(m):
                if rows[i] == 1 or cols[j] == 1:
                    matrix[i][j] = 0
        
        return matrix
        