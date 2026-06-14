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
    int pairSum(ListNode* head) {
        ListNode* a=head;
        ListNode* b=head;
        vector<int>v;
        int n=0;
        while(a!=NULL){
            n++;
            a=a->next;
        }
        for(int i=0;i<n;i++){
            v.push_back(b->val);
            b=b->next;
        }
        int sum=0;
        int i=0;
        
        while(i<=(n/2)-1){
            int t=(v[i]+v[n-1-i]);
            sum=max(sum,t);
            i++;

        }
        return sum;
    }
};