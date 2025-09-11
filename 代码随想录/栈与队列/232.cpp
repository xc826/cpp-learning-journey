#include <iostream>
using namespace std;
#include <stack>

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stackIn.push(x);
    }

    int pop()
    {
        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }

    int peek()
    {
        int res = this->pop();
        stackOut.push(res);
        return res;
    }

    bool empty()
    {
        if (stackOut.empty() && stackIn.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    stack<int> stackIn;
    stack<int> stackOut;
};
