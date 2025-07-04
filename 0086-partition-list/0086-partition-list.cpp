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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* a=new ListNode(100);
        ListNode* b= new ListNode(200);
        ListNode* p=a;
        ListNode* q=b;
        while(temp!=NULL){
            if(x>temp->val){
                p->next=new ListNode(temp->val);
                p=p->next;
            }
            else{
                q->next=new ListNode(temp->val);
                q=q->next;
            }
            temp=temp->next;
        }
        p->next=b->next;
        b->next=NULL;
        return a->next;
    }
};