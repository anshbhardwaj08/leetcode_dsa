class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int smallestValue(int n) {
        if(n==4) return 4;
        while (!isPrime(n)) {
            int sum = 0;
            int x = n;
            for (int i = 2; i <= sqrt(x); i++) {
                while (n % i == 0) {
                    sum += i;
                    n /= i;
                }
            }
            if (n > 1) sum += n; // add the remaining prime
            n = sum;
        }
        return n;
    }

    // int fact(int &a,int sum){
    //     if(a<=1) return 0;
    //     // int sm=0;
    //     // for(int i=2;i<sqrt(a);i++){
    //     //     if(a%i==0){
    //     //         sm=sm+i;
    //     //     }
    //     //     if(sqrt(a)==i+1){
    //     //         sm=sm+1;
    //     //     }
    //     // }
    //     // if(sm==0) return a;
    //     // while(a%2==0){
    //     //     sum=sum+2;
    //     //     a=a/2;
    //     // }
    //     // while(a%3==0){
    //     //     sum=sum+3;
    //     //     a=a/3;
    //     // }

    //     int j=2;
    //     int x=a;
    //     while(j<=sqrt(x)){
    //         if(a%j==0){

    //             a=a/j;
                
    //             sum=sum+j;
    //         }
    //         j++;
    //     }
    //     a=sum;
    //     return fact(a,0);
        
    // }

    // int smallestValue(int n) {
    //     int ans=fact(n,0);
    //     return ans;
        
    // }
};