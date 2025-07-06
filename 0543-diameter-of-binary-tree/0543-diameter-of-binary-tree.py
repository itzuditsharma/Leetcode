# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = [0]
        
        def findDiameter(root)->int:
            if root is None:
                return 0

            lh = findDiameter(root.left)
            rh = findDiameter(root.right)

            diameter[0] = max(diameter[0] , lh+rh)
            return max(lh,rh) + 1

        findDiameter(root)
        return diameter[0]