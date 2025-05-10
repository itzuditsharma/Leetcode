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
        bool isreverse = false;

        BSTiterator(TreeNode* root, bool reverse){
            isreverse = reverse;
            pushAll(root);
        } 

        void pushAll(TreeNode* root){
            while(root){
                if(isreverse == false){
                    st.push(root);
                    root = root -> left;
                }else{
                    st.push(root);
                    root = root -> right;
                }
            }
        }

        int next(){
            TreeNode* node = st.top();
            st.pop();

            if(isreverse == false){
                pushAll(node -> right);
            }else{
                pushAll(node -> left);
            }
            return node -> val;
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
            if(i + j == k){
                return true;
            }

            if(i + j > k){
                j = r.next();
            }else{
                i = l.next();
            }
        }
        return false;
    }
};