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
    ListNode* removeElements(ListNode* head, int key) {
        if(head == NULL) return head;
        if(key > 50 || key < 0){
            return head;
        }
        ListNode* temp = head;

        while(temp != NULL){
            if(temp -> val == key){
                temp = temp -> next;
            }else{
                break;
            }
        }
        head = temp;
        while(temp != NULL&& temp -> next != NULL){
            ListNode* next = temp->next;
            if(next -> val == key){
                temp -> next = next -> next;
                
            }else{
                temp = temp -> next;
            }
        }
        return head;
    }
};