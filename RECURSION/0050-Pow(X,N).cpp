//Method1
class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            return 1 / power(x, -N);
        }
        return power(x, N);
    }
};

//Method2
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long  N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        while(N>0){
            if(N&1){
                ans*=x;
            }
            x*=x;
            N>>=1;
        }
        return ans;
    }
};