class Solution {
public:

    bool isprime(int n){
        if(n<=1) return false;
        for(int i=2;i<=sqrt(n); i++){
            if(n%i==0){
                return false;
            }
        }
        return true;

    }
    bool checkPerfectNumber(int num) {
        if(isprime(num)) return false;

        int i=1;
        int sum=0;
        while(i<=num/2){
            if(num%i==0){
                sum+=i;
            }
            i++;
        }
        if(sum!=num) return false;
        return true;;
    }
};