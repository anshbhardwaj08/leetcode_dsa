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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
       
        if(n%2!=0){
            int idx=(n-1)/2;
            for(int i=0;i<=(n-1)/2;i++){
                head=head->next;
            }
        }
        else{
            int idx=n/2;
            for(int i=0;i<n/2;i++){
                head=head->next;
            }
        }
        return head;
    }
};