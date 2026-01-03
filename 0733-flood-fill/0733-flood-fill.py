class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        key = image[sr][sc]
        image[sr][sc] = color
        n = len(image)
        m = len(image[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        vis[sr][sc] = 1
        q = deque()
        q.append((sr, sc))
        drow = [-1, 0, 1, 0]
        dcol = [0, 1, 0, -1]

        while q:
            (row, col) = q.popleft()
            
            for i in range(4):
                nrow = row + drow[i]
                ncol = col + dcol[i]

                if nrow >=0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0 and image[nrow][ncol] == key:
                    image[nrow][ncol] = color
                    vis[nrow][ncol] = 1
                    q.append((nrow, ncol))

        return image