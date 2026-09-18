class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int rev=0,org=x;
        while(x>0){
            int ld=x%10;
            if(INT_MIN/10>rev or INT_MAX/10<rev) return false;
            rev=rev*10+ld;
            x/=10;
        }
        return rev==org;
    }
};