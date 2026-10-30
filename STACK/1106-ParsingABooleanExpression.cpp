class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char ch : expression) {
            if (ch == ',')
                continue;
            if (ch != ')') {
                st.push(ch);
            }
            else {
                int t = 0, f = 0;
                while (st.top() != '(') {
                    char c = st.top();
                    st.pop();
                    if (c == 't')
                        t++;
                    else
                        f++;
                }
                st.pop();          // Remove '('
                char op = st.top();
                st.pop();
                if (op == '!') {
                    if (f == 1)
                        st.push('t');
                    else
                        st.push('f');
                }
                else if (op == '&') {
                    if (f > 0)
                        st.push('f');
                    else
                        st.push('t');
                }
                else {
                    if (t > 0)
                        st.push('t');
                    else
                        st.push('f');
                }
            }
        }
        return st.top() == 't';
    }
};