#include <iostream>
#include <stack>

using namespace std;

class ParenthesesMatcher {
    private:
        string s;

    public:
    ParenthesesMatcher(string str) {
        this->s = str;
    }

    ParenthesesMatcher(const ParenthesesMatcher& rhs) {
        this->s = rhs.s;
    }

    ~ParenthesesMatcher() {}

    ParenthesesMatcher operator=(const ParenthesesMatcher& rhs) {
        this->s = rhs.s;
        return *this;
    }

    bool matchParentheses() {
        stack<char> st;
        for (int i=0; i<this->s.length(); i++) {
            if (this->s[i] == '(' or this->s[i] == '[' or this->s[i] == '{') {
                st.push(s[i]);
            }
            else if (this->s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (this->s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (this->s[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};


int main()
{
    string input_string = "()()[{}]";
    ParenthesesMatcher object(input_string);
    bool trial = object.matchParentheses();
    if (trial) {
        cout << "Parentheses match!";
    }
    else {
        cout << "Parentheses mismatch!";
    }

    return 0;
}
