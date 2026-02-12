#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a word/symbol: ";
    cin >> s;

    // Check if Integer
    bool isInteger = true;
    for (char c : s) {
        if (!isdigit(c)) {
            isInteger = false;
            break;
        }
    }

    if (isInteger) {
        cout << "It is an Integer." << endl;
        return 0;
    }

    // Check if Identifier
    bool isIdentifier = true;

    // First character must be letter or _
    if (!(isalpha(s[0]) || s[0] == '_')) {
        isIdentifier = false;
    } else {
        for (int i = 1; i < s.length(); i++) {
            if (!(isalnum(s[i]) || s[i] == '_')) {
                isIdentifier = false;
                break;
            }
        }
    }

    if (isIdentifier) {
        cout << "It is an Identifier." << endl;
        return 0;
    }

    // Check if Operator
    string operators[] = {
        "+", "-", "*", "/", "%", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!"
    };

    for (string op : operators) {
        if (s == op) {
            cout << "It is an Operator." << endl;
            return 0;
        }
    }

    // Check if Punctuation
    if (s.length() == 1 && ispunct(s[0])) {
        cout << "It is a Punctuation symbol." << endl;
        return 0;
    }

    // If none match
    cout << "Unknown / Invalid token." << endl;

    return 0;
}