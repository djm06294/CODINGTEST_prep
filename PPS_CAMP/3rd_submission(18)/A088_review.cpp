// 문제: 항상 minimum element를 출력할 수 있는 stack 구현하기.

// 본래의 stack을 쌓을 때 또 다른 스텍 하나에도 넣어주는데, 거기에는 기존의 들어있는 값보다 작은 값만 쌓을 수 있도록 했다. 그리고 pop할 때는 일치할 경우 같이 pop해줬다.
// 이 방법으로 구현이 안될 거라고 생각했는데, stack은 차례대로 pop할 수 밖에 없기 때문에 되는구나.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack {
public:
    vector<int>st;
    vector<int>mini;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(mini.size()==0 or mini.back()>=val)
        mini.push_back(val);
    }
    
    void pop() {
        if(st.back()==mini.back())
        mini.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mini.back();
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