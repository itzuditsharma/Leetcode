/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int &maxsum){
        if(root == NULL) return 0;

        int lh = max(0, helper(root->left, maxsum));
        int rh = max(0, helper(root -> right, maxsum));

        maxsum = max(maxsum, lh + rh + root -> val);
        return max(lh, rh) + root -> val;
    }

    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        helper(root, maxsum);
        return maxsum;
    }
};