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
class BSTiterator{
    public:
        stack<TreeNode*> st;
        bool reverse = true;

        BSTiterator(TreeNode* root, bool isreverse){
            reverse = isreverse;
            pushAll(root);
        }

        int next(){
            TreeNode* node = st.top();
            st.pop();

            if(reverse == false){
                pushAll(node -> right);
            }else{
                pushAll(node -> left);
            }

            return node -> val;
        }

        void pushAll(TreeNode* root){
            while(root){
                st.push(root);
                if(reverse == false){
                    root = root ->left;
                }else{
                    root = root -> right;
                }
            }
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k) return true;

            if(i + j > k){
                j = r.next();
            }else{
                i = l.next();
            }
        }
        return false;
    }
};