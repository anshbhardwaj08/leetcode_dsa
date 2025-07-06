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

    ListNode* reverselist(ListNode* head){
    if(head->next==NULL) return head;
    ListNode* newhead= reverselist(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        ListNode* s=head;
        ListNode* f=head;
        while(f->next!=NULL && f->next->next!=NULL ){
            s=s->next;
            f=f->next->next;
        }
        // s is at left middle
        ListNode* a=s->next;
        s->next=NULL;
        ListNode* rev=reverselist(a);
        ListNode* temp=head;
        ListNode* ta=head;
        ListNode* b=rev;
        ListNode* tb=rev;
        ListNode* c=new ListNode(100);
        ListNode* tc=c;
        while(ta!=NULL && tb!=NULL){
            tc->next=ta;
            ta=ta->next;
            tc=tc->next;
        
            tc->next=tb;
        
            tb=tb->next;
            tc=tc->next;
        }
        tc->next=ta;
        head=c->next;
        c->next=NULL;
        

    }
};