#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <string>

using namespace std;


class STACK{
    public:
    bool isValid(string s);
    int evalRPN(vector<string> tokens);
    vector<string> generateParenthesis(int n);
};

class MinStack{
    public:
    void push(int val);
    void pop();
    int top();
    int getMin();
    private:
    vector<pair<int,int>> s;
};

#endif