class Solution {
public:
    bool isValid(string s) {
        stack<char> st;                           // Stack to store opening brackets

        for (char ch : s) {                       // Traverse each character

            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);                      // Push opening bracket
            }

            else {                                // Closing bracket found

                if (st.empty())                   // No opening bracket available
                    return false;

                char top = st.top();              // Get top opening bracket
                st.pop();                         // Remove it

                if ((ch == ')' && top != '(') || // Check matching pair
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;                 // Invalid pair
                }
            }
        }

        return st.empty();                        // Valid only if stack empty
    }
};