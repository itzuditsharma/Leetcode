class Solution:
    def helper(self, rows):
        ans = 1
        temp = []
        temp.append(ans)

        for i in range(1, rows):
            ans = ans * (rows - i)
            ans //= i
            temp.append(ans)
        
        return temp

    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        for i in range(1, numRows+1):
            ans.append(self.helper(i))
        
        return ans