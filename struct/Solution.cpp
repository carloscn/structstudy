#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {

public :

    stack<char> mStack;

    bool isValid(string s) {

        for ( int i = 0; i < s.length(); i ++) {
            char c = s.at(i);
            if ( c == '(' || c == '[' || c == '{') {
                mStack.push(c);
            }else {
                if ( mStack.empty() )
                    return false;

                char topChar = mStack.top();
                mStack.pop();

                if( topChar == '(' && c == ')' ) {
                    return false;
                }

                if( topChar == '[' && c == ']' ) {
                    return false;
                }

                if( topChar == '{' && c == '}' ) {
                    return false;
                }
            }
        }

        return mStack.empty();

    };
};

