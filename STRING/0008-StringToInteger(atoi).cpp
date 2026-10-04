class Solution {
public:
    int helper(string &s,int i,long long num,int sign){
        if (i >= s.size() || !isdigit(s[i]))
            return sign * num;
        int digit = s[i] - '0';
        if (num > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        num= num * 10 + digit;
        return helper(s, i + 1, num, sign);
    }
    int myAtoi(string s) {
      int i=0;
      while(i<s.size() && s[i]==' ')  i++;
      int sign=1;
      if(i<s.size() && (s[i]=='+' || s[i]=='-')){
        if(s[i]=='-'){
            sign=-1;
        }
        i++;
      }
      return helper(s,i,0,sign);
    }
};