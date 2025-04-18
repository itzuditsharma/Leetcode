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
    int leftHeight(TreeNode* root){
        int count = 0;
        while(root -> left){
            root = root -> left;
            count++;
        }
        return count;
    }
    int rightHeight(TreeNode* root){
        int count = 0;
        while(root -> right){
            root = root -> right;
            count++;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) ((1 << lh)  - 1);

        return countNodes(root->left) + countNodes(root ->right) + 1;
    }
};