class Solution {
public:
    bool isValid(string s) {

        // Stack is used to store opening brackets
        // because we need to match the most recent
        // opening bracket first (LIFO)
        stack<char> st;

        // Traverse every character in the string
        for (int i = 0; i < s.size(); i++) {

            // If the character is an opening bracket,
            // store it in the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }

            // Otherwise, the character is a closing bracket
            else {

                // If there is no opening bracket available,
                // this closing bracket has nothing to match
                if (st.size() == 0) {
                    return false;
                }

                // Check whether the top opening bracket
                // matches the current closing bracket
                if ((st.top() == '(' && s[i] == ')')
                    || (st.top() == '[' && s[i] == ']')
                    || (st.top() == '{' && s[i] == '}')) {

                    // Matching pair found, remove the
                    // opening bracket from the stack
                    st.pop();
                }

                // Brackets do not match
                else {
                    return false;
                }
            }
        }

        // Stack must be empty after processing the entire string.
        // If something remains, there is an unmatched opening bracket.
        return st.size() == 0;
    }
};