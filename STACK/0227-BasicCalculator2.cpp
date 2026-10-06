class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long number = 0;
        char sign = '+';
        for (int i = 0; i <= s.length(); i++) {
            if (i < s.length() && isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }
            else if (i == s.length() || s[i] != ' ') {
                if (sign == '+') {
                    st.push(number);
                }
                else if (sign == '-') {
                    st.push(-number);
                }
                else if (sign == '*') {
                    long long top = st.top();
                    st.pop();
                    st.push(top * number);
                }
                else if (sign == '/') {
                    long long top = st.top();
                    st.pop();
                    st.push(top / number);
                }
                number = 0;
                if (i < s.length()) {
                    sign = s[i];
                }
            }
        }
        long long result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return (int)result;
    }
};