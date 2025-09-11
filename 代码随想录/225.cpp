#include <iostream>
using namespace std;
#include <queue>

class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int size=q.size();
        size--;
        while(size--)
        {
            q.push(q.front());
            q.pop();
        }

        int res=q.front();
        q.pop();
        return res;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};