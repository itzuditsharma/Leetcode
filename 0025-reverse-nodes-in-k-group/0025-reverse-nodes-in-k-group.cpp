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
    ListNode* getkthNode(ListNode* temp, int k){
        k--;
        while(temp!= NULL && k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL){
            ListNode* next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL){
            ListNode* kthnode = getkthNode(temp, k);
            if(kthnode == NULL){
                if(prevLast) prevLast -> next = temp;
                break;
            }

            ListNode* nextNode = kthnode -> next;
            kthnode -> next = NULL;

            reverseLL(temp);
            if(temp == head){
                head = kthnode;
            }else{
                prevLast -> next = kthnode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
        
    }
};