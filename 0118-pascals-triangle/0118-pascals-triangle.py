class Solution:
    def InsertVal(self, rows):
        temp = []
        ans = 1
        temp.append(ans)

        for i in range(1,rows):
            ans = ans * (rows - i)
            ans = ans // i
            temp.append(ans)

        return temp

    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        for i in range(1, numRows + 1):
            ans.append(self.InsertVal(i))
        return ans