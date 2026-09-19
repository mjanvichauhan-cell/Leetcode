//Method1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return 0;
        while(n!=1){
            if(n%2==1){
                return 0;
            }
            n=n/2;
        }
        return 1;
    }
};

//Method2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return  (n>0 &&!(n & n-1));
    }
};