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

    void helper(TreeNode* root, int k, int &k_smallest, int &counter){
        if(!root || counter >= k) return;

        helper(root -> left, k, k_smallest, counter);
        counter++;
        if(counter == k){
            k_smallest = root -> val;
            return;
        }
        helper(root -> right, k, k_smallest, counter);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int k_smallest;
        helper(root, k, k_smallest, counter);
        return k_smallest;
    }
};