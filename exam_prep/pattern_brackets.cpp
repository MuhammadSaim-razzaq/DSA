#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidPattern(const string& text, const string& pattern) {
    char openB = pattern[0];
    char closeB = pattern[1];
    stack<char> st;

    for(char c : text) {
        if(c == openB) {
            st.push(c);   // push only brackets from pattern
        }
        else if(c == closeB) {
            if(st.empty()) return false;  // no opening bracket
             // mismatch
            st.pop();   // matched
        }
        // ignore all other characters
    }

    return st.empty();  // valid if no unmatched brackets left
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern (like () or {}): ";
    cin >> pattern;

    if(isValidPattern(text, pattern))
        cout << "VALID\n";
    else
        cout << "INVALID\n";

    return 0;
}
