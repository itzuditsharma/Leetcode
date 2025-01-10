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
    stack<TreeNode*> st;
    bool reverse = true;

    public:
    BSTiterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(!reverse) pushAll(node -> right);
        else pushAll(node -> left);

        return node -> val;
    }

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse == true){
                node = node -> right;
            }else{
                node = node -> left;
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