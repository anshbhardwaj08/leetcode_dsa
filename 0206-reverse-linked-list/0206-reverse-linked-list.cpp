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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode*a =new ListNode(100);
        ListNode* b=a;
        while(head->next!=NULL){
            ListNode*temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            a->next=new ListNode(temp->next->val);
            temp->next=NULL;
            a=a->next;



        }
        a->next=new ListNode(head->val);
        return b->next;
        
    }
};