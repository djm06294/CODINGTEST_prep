// 문제: 항상 minimum element를 출력할 수 있는 stack 구현하기.

// stack에 쌓을 때마다 min도 pair로 함께 저장해주었다.
// 신박하면서도 깔끔한 것 같다. 런타임 메모리도 적게 차지했다.
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> stack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stack.size() == 0)
        {
            stack.push({val, val});
        }
        else
        {
            stack.push({val, min(stack.top().second, val)});
        }
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }
};