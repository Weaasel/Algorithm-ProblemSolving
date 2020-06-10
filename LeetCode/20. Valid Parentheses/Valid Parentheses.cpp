class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> st;
        for(int i=0;i<len;i++) {
            if(st.empty()) st.push(s[i]);
            else {
                if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else if(s[i] == '}' && st.top() == '{') {
                    st.pop();
                }
                else if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                }
                else st.push(s[i]);
            }
        }
        return st.empty();
    }
};
