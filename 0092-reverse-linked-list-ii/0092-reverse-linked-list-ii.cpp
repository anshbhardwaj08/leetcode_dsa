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
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead= reverselist(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right ) return head;
        if(head==NULL || head->next==NULL) return head;
        ListNode*a=head;
        ListNode*b=head;
        ListNode*c=head;
        ListNode*d=head;
        int i=1;
        while(i!=left){
            a=a->next;
            i++;
        }
        int j=1;
        while(j!=right){
            c=c->next;
            j++;
        }
        if(b==a && c->next==NULL){
            c=reverselist(a);// humne reversed list ke head ko c bna diya 
            return c;
        }
        if(b==a && c->next!=NULL){
            while(d!=c->next){
            d=d->next;
            }
            c->next=NULL;
            
            c=reverselist(a);

            a->next=d;
            return c;

        }
        if(c==d && b->next!=a){
            while(d!=c->next){
            d=d->next;
            }
            b->next=NULL;
            
            c=reverselist(a);
            b->next=c;
            return head;

        }
        while(b->next!=a){
            b=b->next;
        }
        while(d!=c->next){
            d=d->next;
        }
        c->next=NULL;
        b->next=NULL;
        //new we have a node with head as a;
        c=reverselist(a);
        
        b->next=c;
        a->next=d;
        return head;


    }
};