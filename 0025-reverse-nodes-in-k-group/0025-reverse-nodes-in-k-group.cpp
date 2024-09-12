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
        ListNode* prev = NULL;
        ListNode* temp = head;

        while(temp != NULL){
            ListNode* next_node = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next_node;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp,int k){
        k--;
        while(k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL){
            ListNode* kthNode = getKthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode) {
                    prevNode -> next = temp;
                    break;
                }
            }

            ListNode* next_node = kthNode -> next;
            kthNode -> next = NULL;

            reverseLL(temp);

            if(head == temp){
                head = kthNode;
            }else{
                prevNode -> next = kthNode;
            }

            prevNode = temp;
            temp = next_node;
        }
        return head;
    }
};