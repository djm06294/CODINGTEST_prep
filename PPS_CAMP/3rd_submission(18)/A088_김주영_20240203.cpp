// 24.02.03 SAT
// JOOYOUNG KIM
// https://leetcode.com/problems/min-stack/description/

// lil slow & memory large

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack {
public:
    vector<int> V;
    MinStack() {
        
    }
    
    void push(int val) {
        V.push_back(val);        
    }
    
    void pop() {
        V.pop_back();        
    }
    
    int top() {
        return V.back();        
    }
    
    int getMin() {
        vector<int> tmp = V;    //deep copy
        sort(tmp.begin(), tmp.end());
        return tmp[0];        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */