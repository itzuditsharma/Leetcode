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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Delete a single Node 
        if(head -> next == NULL && n==1) return nullptr;
        int count = 0;
        ListNode* temp = head;

        while(temp!= NULL){
            count++;
            temp = temp -> next;
        }
        
        // Delete the first element 
        if(count == n){
            head = head -> next;
            return head;
        }

        int k = count - n;

        count = 0;
        temp = head;
        while(temp != NULL && temp -> next != NULL){
            count++;
            if(count == k){
                temp -> next = temp -> next -> next;
                break;
            }
            temp = temp -> next;
        }
        return head;

    }
};