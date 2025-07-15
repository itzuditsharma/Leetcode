# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def helper(self, root, ans):
        if root == None:
            return 
        self.helper(root.left, ans)
        ans.append(root.val)
        self.helper(root.right, ans)

    def inorderTraversal(self, root):
        ans = []
        self.helper(root, ans)
        return ans
       
        