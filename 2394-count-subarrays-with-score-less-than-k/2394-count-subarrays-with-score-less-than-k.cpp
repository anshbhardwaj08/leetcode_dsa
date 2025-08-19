class Solution {
public:
    long long countSubarrays(vector<int>&a, long long k) {
        
        long long int i=0,j=0,sum=0,score=0,ans=0;
        long long int n = a.size();
        while(i < n and j < n){
        sum += a[j]; //window expansion
        score = sum*(j-i+1);
            while(i<=j and score >= k){
            //window contraction
                sum -= a[i++];
                score = sum*(j-i+1);
            }
            ans += (j-i+1);
            j++;
        }
        return ans;

        
    }
};