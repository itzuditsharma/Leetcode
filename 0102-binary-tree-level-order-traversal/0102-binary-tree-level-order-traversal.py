# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        ans = []
        q = deque()
        q.append(root)

        if root is None:
            return ans

        while q:
            size = len(q)
            temp = []

            for _ in range(size):
                node = q.popleft()
                temp.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                
            ans.append(temp)

        return ans
        

        