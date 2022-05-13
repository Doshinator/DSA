#include "stack.h"
#include <string>
#include <stack>
#include <unordered_map>
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

void MinStack::push(int val){
    if(s.empty())
        s.push_back({val,val});
    else 
        s.back().second < val? s.push_back({val, s.back().second}) : s.push_back({val, val});
}

void MinStack::pop(){
    if(!s.empty())
        s.pop_back();
}

int MinStack::top(){
    return s.back().first;
}

int MinStack::getMin(){
    return s.back().second;
}


int STACK::evalRPN(vector<string> tokens){
    // push onto the stack until you hit operator - pop off two from stack 
    // and continue to push until no more operator left
    //Input: tokens = ["2","1","+","3","*"]
    // Output: 9
    // Explanation: ((2 + 1) * 3) = 9
    
    stack<int> s;
    unordered_map<string, function<int (int, int)>> m {
        {"+", [] (int a, int b) {return a + b;} },
        {"-", [] (int a, int b) {return a - b;} },
        {"*", [] (int a, int b) {return a * b;} },
        {"/", [] (int a, int b) {return a / b;} },
    };

    for(int i = 0; i < tokens.size(); i++){
        if(m.find(tokens[i]) == m.end())
            s.push(stoi(tokens[i]));
        else{
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();
            // ig. 13 5 / -> op 1 = 5, op 2 = 13 -> op2 / op1 -> (13 / 5) 
            s.push(m[tokens[i]](op2, op1));
        }
    }
    return s.top();
}


vector<string> STACK::generateParenthesis(int n){
    // Input: n = 3
    // Output: ["((()))","(()())","(())()","()(())","()()()"]
    vector<string> res;
    std::stack<char> stack;
    //     (
    //    / \
    //   ((  ()
    //   / \
    // ((( (()
    



    return res;
}