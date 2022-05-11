#ifndef STACK_H_
#define STACK_H_

#include <vector>
#include <string>

using namespace std;


class STACK{
    public:
    bool isValid(string s);
    void push(int val);
    void pop();
    int top();
    int getMin();
};


#endif