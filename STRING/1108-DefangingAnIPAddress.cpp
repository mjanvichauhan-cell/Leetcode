class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for(char c: address) {
            if(c == '.') {
                result += "[.]";
                continue;
            }
            result.push_back(c);
        }
        return result;
    }
};