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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int len1=0;
        int len2=0;
        ListNode* a=list1;
        ListNode* b=list2;
        while(a!=NULL){
            len1++;
            a=a->next;
        }
        while(b!=NULL){
            len2++;
            b=b->next;
        }
        int s=min(len1,len2);
        if(len1==0 && len2==0){
            return list1;
        }
        if(len1==0) return list2;
        if(len2==0) return list1;
        if(len1==1 && len2==0) return list1;
        if(len2==1 && len1==0) return list2;
        a=list1;
        b=list2;
        ListNode* list3;
        if(list1->val>=list2->val){
            list3= new ListNode(list2->val);
            list2=list2->next;
        }
        else{
            list3=new ListNode(list1->val);
            list1=list1->next;
        }
        int i=1;
        ListNode* temp = list3;
        while(list1!=NULL && list2!=NULL){
            // if(list1==NULL){
            //     while(list2!=NULL){
            //         temp->next=new ListNode(list2->val);
            //         list2=list2->next;
            //         temp=temp->next;
            //     }
            // }
            // if(list2==NULL){
            //     while(list1!=NULL){
            //         temp->next=new ListNode(list1->val);
            //         list1=list1->next;
            //         temp=temp->next;
            //     }
            // }

            if(list1->val>=list2->val){
                temp->next=new ListNode(list2->val);
                list2=list2->next;
                temp=temp->next;
            }
            else{
                temp->next=new ListNode(list1->val);
                list1=list1->next;
                temp=temp->next;
            }
            if(list1==NULL) break;
            if(list2==NULL) break;
        }
        if(list1==NULL){
            temp->next=list2;
            }
        if(list2==NULL){
            temp->next=list1;
        }
        return list3;
    }
};