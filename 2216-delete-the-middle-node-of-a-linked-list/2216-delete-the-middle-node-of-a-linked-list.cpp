/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // The code that helps avoid using prev 
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        fast = fast -> next -> next;


        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};