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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;  // Handle edge cases
        }
        int len = 1;
        ListNode* temp = head;

        while(temp -> next != NULL){
            len++;
            temp = temp -> next;
        }
        if(k%len ==0) return head;
        k = k % len;
        
        temp -> next = head;

        int n = len - k;
        temp = head;

        for(int i = 1; i < n; i++){
            temp = temp -> next;
        }
        head = temp -> next;
        temp -> next = NULL;

        return head;
    

    }
};