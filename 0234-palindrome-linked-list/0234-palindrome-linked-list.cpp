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
    ListNode* ReverseLL(ListNode* head){
        if(head == NULL || head -> next == NULL) return head;

        ListNode* new_head = ReverseLL(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return new_head;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != NULL && fast -> next -> next!= NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* new_head = ReverseLL(slow -> next);
        ListNode* first = head;
        ListNode* second = new_head;

        while(second != NULL){
            if(first->val != second->val ){
                ReverseLL(new_head);
                return false;
            }

            first = first -> next;
            second = second -> next;
        }
        ReverseLL(new_head);
        return true;
    }
};