class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,ld=0,mul=1;
        while(n>0){
            ld=n%10;
            n=n/10;
            sum=sum+ld;
            mul=mul*ld;
        }
        return mul-sum;
    }
};