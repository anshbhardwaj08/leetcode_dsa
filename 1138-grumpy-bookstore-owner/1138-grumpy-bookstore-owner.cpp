class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> &arr=customers;
        int k=minutes;
        int loss=0;
        // if(arr.size()==1) return arr[0];
        for(int i=0;i<k;i++){
            if(grumpy[i]==1) loss+=arr[i];
        }    

        int i=1;
        int j=k;
        int maxloss=loss;
        int idx=0;
        
        while(j<arr.size()){
            int currloss=loss;    
            if(grumpy[j]==1) currloss+=arr[j];
            if(grumpy[i-1]==1) currloss-=arr[i-1];
            
            if(currloss>maxloss){
                maxloss=currloss;
                idx=i;
            }
            loss=currloss;

            i++;
            j++;


        }

        for(int i=idx;i<k+idx;i++){
            grumpy[i]=0;
        }
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(grumpy[i]==0){
                ans+=arr[i];
            }
        }
        return ans;
    }
};