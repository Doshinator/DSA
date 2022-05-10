#include "stack.h"

#include <string>
#include <stack>
using namespace std;

bool STACK::isValid(string s){
    // Input: s = "()[]{}"
    // Output: true
    stack<char> stk;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            stk.push(s[i]);

        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if((stk.top() == '(' && s[i] != ')') || (stk.top() == '[' && s[i] != ']') || (stk.top() == '{' && s[i] != '}'))
                return false;
            else
                stk.pop();

        }
    }
    // stack should be empty - true : valid paren , else false ; invalid paren
    return stk.empty();
}