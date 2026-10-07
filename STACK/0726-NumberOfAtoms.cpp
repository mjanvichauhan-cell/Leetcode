class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push(map<string, int>());
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                st.push(map<string, int>());
                i++;
            }
            else if (formula[i] == ')') {
                map<string, int> current = st.top();
                st.pop();
                i++;
                int multiplier = 0;
                while (i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10 +(formula[i] - '0');
                    i++;
                }
                if (multiplier == 0)
                    multiplier = 1;
                for (auto &p : current) {
                    st.top()[p.first] += p.second * multiplier;
                }
            }
            else {
                string atom;
                atom += formula[i];
                i++;
                while (i < n && islower(formula[i])) {
                    atom += formula[i];
                    i++;
                }
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 +
                            (formula[i] - '0');
                    i++;
                }
                if (count == 0)
                    count = 1;
                st.top()[atom] += count;
            }
        }
        string ans;
        for (auto &p : st.top()) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};