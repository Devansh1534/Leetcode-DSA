class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        vector<bool> to_remove(s.size(), false);
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    to_remove[i] = true;
                }
            }
        }
        
        while (!st.empty()) {
            to_remove[st.top()] = true;
            st.pop();
        }
        
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (!to_remove[i]) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};
