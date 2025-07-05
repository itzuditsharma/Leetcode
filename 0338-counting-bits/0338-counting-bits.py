class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = []
        while n >= 0:
            count = 0
            element = n

            while element > 0:
                if element % 2 == 1:
                    count += 1
                element //= 2

            ans.append(count)
            n -= 1

        return ans[::-1]