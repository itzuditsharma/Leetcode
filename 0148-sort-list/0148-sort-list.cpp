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

// Sorting list by doing merge sort 
class Solution {
public:
    // Find middle node of  ll
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;  //Just a little change to tortoise and hare 

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    } 

    // Merge two sorted lists 
    ListNode* MergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* dummy_node = new ListNode(-1);
        ListNode* temp = dummy_node;

        while(l1!= NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                temp -> next = l1;
                temp = l1;
                l1 = l1 -> next;
            }else{
                temp -> next = l2;
                temp = l2;
                l2 = l2 -> next;
            }
        }

        if(l1 != NULL) temp ->next = l1;
        if(l2 != NULL) temp ->next = l2;

        return dummy_node -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode * left = head;
        ListNode* right = middle-> next;
        middle -> next = NULL;

        left = sortList(left);    
        right = sortList(right);    

        return MergeTwoLists(left, right);
    }
};