
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