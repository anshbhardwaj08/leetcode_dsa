
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ta=list1;
        ListNode* tc=list1;
        ListNode* tb=list2;
        int i=0;
        while(i<a-1){
            ta=ta->next;
            i++;
        }// ta is at a-1 pos

        int j=0;
        while(j<b){
            tc=tc->next;
            j++;
        }
 
        while(tb->next!=NULL){
            tb=tb->next;
            
        }
        ta->next=list2;
        tb->next=tc->next;
        tc->next=NULL;
        return list1;
        


    }
};