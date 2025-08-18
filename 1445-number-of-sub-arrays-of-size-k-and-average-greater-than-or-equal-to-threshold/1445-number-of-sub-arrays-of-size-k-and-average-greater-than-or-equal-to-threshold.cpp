class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int i=0;
        int j=k;
        int n=arr.size();
        int sum=0;
        int avg=0;
        int count=0;
        if(k==1){
            for(int i=0;i<n;i++){
                if(arr[i]>=t){
                    count++;
                }
            }
            return count;
        }
        if(k>n){
            k=k%n;
        }
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        avg=sum/k;
        if(avg>=t){
            count++;
        }

        
        while(j<n){
            sum=sum-arr[i]+arr[j];
            avg=sum/k;
            if(avg>=t){
                count++;
            }
            i++;
            j++;

        }
        return count;

    }
};