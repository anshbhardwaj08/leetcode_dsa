class Solution {
public:

    ListNode* reverselist(ListNode* head){
    if(head->next==NULL) return head;
    ListNode* newhead= reverselist(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL|| head->next==NULL) return true;
        
        
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
        ListNode* p=rev;
        ListNode* q=head;
        while(p!=NULL ){
            if(p->val!=q->val) return false;
            p=p->next;
            q=q->next;
        }
        return true;
        
        
    }
};