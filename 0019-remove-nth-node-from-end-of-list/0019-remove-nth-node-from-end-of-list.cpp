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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x=0;
        ListNode*temp=head;
        while(temp!=NULL){
            x++;
            temp=temp->next;
        }
        if(n==x){
            head=head->next;
            return head;
        }
        temp=head;
        for(int i=1;i<=x-n-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};