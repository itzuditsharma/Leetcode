/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mapp;
        ListNode* temp = head;

        while(temp != NULL && temp ->next != NULL){
            if(mapp.find(temp) != mapp.end()){
                return temp;
            }
            mapp[temp]++;
            temp = temp -> next;
        }
        return NULL;
    }
};