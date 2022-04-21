#include "test.h"
#include <iostream>
#include <unordered_set>
#include <unordered_map>


int Test::totalCases = 0;
int Test::passedCases = 0;

Test::Test(int expected, int result){
    totalCases++;
    if(expected == result){
        cout << "Test" << GREEN << " Passed " << RESET << ": (expected: " << expected << ", result: " << result << ")" << endl;
        passedCases++;
    } else {
        cout << "Test" << RED << " Failed " << RESET << ": (expected: " << expected << ", result: " << result << ")" << endl;    
    }
}

Test::Test(string expected, string result){
    totalCases++;
    if(expected == result){
        cout << "Test" << GREEN << " Passed " << RESET << ": (expected: " << expected << ", result: " << result << ")" << endl;
        passedCases++;
    } else {
        cout << "Test" << RED << " Failed " << RESET << ": (expected: " << expected << ", result: " << result << ")" << endl;    
    }
}

Test::Test(vector<int> expected, vector<int> result){
    totalCases++;
    if(expected == result){
        cout << "Test" << GREEN << " Passed " << RESET << ": (expected: "; printVector(expected);  cout << ", result: "; printVector(result); cout << ")" << endl; 
        passedCases++;
    } else {
        cout << "Test" << RED << " Failed " << RESET << ": (expected: "; printVector(expected); cout << ", result: "; printVector(result); cout << ")" << endl;    
    }
}

Test::Test(vector<string> expected, vector<string> result){
    totalCases++;
    if(expected == result){
        cout << "Test" << GREEN << " Passed " << RESET << ": (expected: "; printVector(expected);  cout << ", result: "; printVector(result); cout << ")" << endl; 
        passedCases++;
    } else {
        cout << "Test" << RED << " Failed " << RESET << ": (expected: "; printVector(expected); cout << ", result: "; printVector(result); cout << ")" << endl;    
    }
}

void Test::printVector(vector<int> v){
    cout << "{";
    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "}";
}

void Test::printVector(vector<string> v){
    cout << "{";
    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "}";
}

void Test::printResult(){
    cout << passedCases << " / " << totalCases <<  " Total Cases Passed" << endl;
}