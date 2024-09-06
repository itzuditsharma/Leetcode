/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  Not a recommended solution 
// Have time and space complexity 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mapp;
        ListNode* temp = head;

        while(temp != NULL){
            if(mapp.find(temp) != mapp.end()){
                return true;
            }
            mapp[temp]++;
            temp = temp -> next;
        }
        return false;
    }
};