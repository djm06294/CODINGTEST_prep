// 24.01.30 TUE
// JooYoung Kim
// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> _s1;
    stack<int> _s2;
    int newElementCount = 0;

    MyQueue() {
        
    }
    // 1 2 3 ||  3개 pop || 1 2 3 3을 pop 
    void push(int x) {
        _s1.push(x);
        newElementCount++;        
    }
    
    int pop() {

        
    }
    
    int peek() {
        
    }
    
    bool empty() {
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */