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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       
        map<ListNode*,bool> visited;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=NULL){
          visited[tempA]=true;
        // tempA->val==0;
          tempA=tempA->next;
        }
        while(tempB!=NULL){
            if(visited[tempB]==true){
                return tempB;
            }
            tempB=tempB->next;
        }
     return NULL;
    }
};