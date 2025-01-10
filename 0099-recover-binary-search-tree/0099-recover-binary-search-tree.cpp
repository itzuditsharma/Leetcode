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
    void inordertraversal(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        inordertraversal(root -> left, inorder);
        inorder.push_back(root -> val);
        inordertraversal(root -> right, inorder);
    }

    void helper(TreeNode* root, vector<int> &vec, int &i){
        if(!root || i > vec.size()) return;

        helper(root -> left, vec, i);
        if(root -> val != vec[i]){
            root-> val = vec[i];
        }
        i++;
        helper(root -> right, vec, i);
    }


    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        inordertraversal(root, inorder);
        sort(inorder.begin(), inorder.end());
        int i = 0;
        helper(root, inorder, i);
    }
};