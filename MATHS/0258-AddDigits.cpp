class Solution {
public:
    int addDigits(int num) {
   while(num>9){
    int ans=0;
    while(num!=0){
        int ld=num%10;
        ans=ans+ld;
        num/=10;
    }
    num=ans;
   }
   return num;
    }
};