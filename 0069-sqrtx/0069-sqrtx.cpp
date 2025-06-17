class Solution {
public:
    int mySqrt(int x) {
        int lo=0;
        int high=x;
        
        
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            long long m=(long long)mid;
            long long y = (long long)x;
            if((m*m)==y){
                return mid;
            }
            if(m*m>y){
                high=m-1;

            }
            if(m*m<y){
                lo=m+1;
            }
        }
        return high;
        
    }
};