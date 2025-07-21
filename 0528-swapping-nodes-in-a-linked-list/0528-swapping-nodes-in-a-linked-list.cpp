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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*>v;
        
        int n=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
            n+=1;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<=n;i++){
            v.push_back(temp);
            temp=temp->next;
        }

        int i=0;
        int j=n;
        while(i<=n){
            if( i==k-1 && j==n-k+1 ){
                int m=v[i]->val;
                v[i]->val=v[j]->val;
                v[j]->val=m;
                break;
            }
            i++;
            j--;
        }
        return head;

    }
};