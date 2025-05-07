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
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        queue<pair<TreeNode*, int>> q;  // node, index
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            int first, last;
            int mmin = q.front().second;

            for(int i = 0; i < size; i++){
                int curr_index = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) first = curr_index;
                if(i == size - 1) last = curr_index;
                if(node -> left) q.push({node -> left, 2 * (long long)curr_index + 1});
                if(node -> right) q.push({node -> right, 2 * (long long)curr_index + 2});
            }
            width = max(width, last - first + 1);
        }
        return width;
    }
};