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
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* next_node = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next_node;
        }
        return prev;
    }


    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast -> next ->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* new_head = reverseLL(slow -> next);
        ListNode* temp1 = head;
        ListNode* temp2 = new_head;

        while(temp2!= NULL){
            if(temp1->val != temp2->val) return false;

            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
};