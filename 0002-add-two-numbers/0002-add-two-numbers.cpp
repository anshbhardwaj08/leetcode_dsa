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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a=l1;
        ListNode* b=l2;
        ListNode* temp=new ListNode(100);
        ListNode* t=temp;
        int carry=0;
        while(a!=NULL || b!=NULL || carry!=0){
            int val1 = (a != NULL) ? a->val : 0;
            int val2 = (b != NULL) ? b->val : 0;
            int sum = val1 + val2 + carry;
           
            int val=sum;
            int e=val%10;
            carry=val/10;
            t->next=new ListNode(e);
            if(a!=NULL) a=a->next;
            if(b!=NULL) b=b->next;
            t=t->next;



        }
        return temp->next;
    }
};