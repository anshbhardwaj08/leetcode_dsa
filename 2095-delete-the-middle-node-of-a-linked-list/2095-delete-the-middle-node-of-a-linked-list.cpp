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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        
        int n=0;
        
        ListNode* temp=head;
        while(temp!=NULL){
            n+=1;
            temp=temp->next;
        }
        temp=head;
        ListNode* s=head;
        ListNode* f=head;

        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
        } // now s has become the left middle 
        if(n%2==0) s=s->next;
        while(temp->next!=s){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        s->next=NULL;
        return head;

    }
};