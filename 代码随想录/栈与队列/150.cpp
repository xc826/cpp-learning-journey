#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (string st : tokens)
        {
            if (st == "+" || st == "-" || st == "*" || st == "/")
            {
                int top1 = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                int temp = 0;

                if (st == "+")
                    temp = top2 + top1;
                if (st == "-")
                    temp = top2 - top1;
                if (st == "*")
                    temp = top2 * top1;
                if (st == "/")
                    temp = top2 / top1;

                s.push(temp);
            }
            else
            {
                s.push(stoi(st));
            }
        }
        return s.top();
    }
};

int main()
{
    Solution sol;
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    int ans = sol.evalRPN(tokens);

    cout << ans << endl;
}