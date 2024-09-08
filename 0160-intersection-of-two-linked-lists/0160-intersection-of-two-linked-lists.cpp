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
    ListNode* collisionPoint(ListNode *t1, ListNode *t2, int diff){
        while(diff){
            t2 = t2 -> next;
            diff--;
        }

        while(t1 != t2){
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        return t1;
    }

    // using 2 pointers to avoid space complexity 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;

        int count1 = 0;
        int count2 = 0;

        while(t1!=NULL){
            count1++;
            t1 = t1 -> next;
        }

        while(t2 != NULL){
            count2++;
            t2 = t2 -> next;
        }

        if(count1 < count2){
            return collisionPoint(headA, headB, (count2-count1));
        }else{
            return collisionPoint(headB, headA, (count1-count2));
        }
    }
};