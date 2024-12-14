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
    int helper(TreeNode* root, int &max_sum){
        if(root==NULL) return 0;

        int lh = max(0, helper(root->left, max_sum));
        int rh = max(0, helper(root->right, max_sum));
        

        max_sum = max(max_sum, lh + rh + root -> val);
        return max(lh, rh) + root -> val;
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        helper(root, max_sum);
        return max_sum;
    }
};