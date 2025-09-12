#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {

            if (!st.empty() && s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    string s = "abbaca";
    Solution sol;
    string res = sol.removeDuplicates(s);
    for (char c : res)
    {
        cout << c;
    }
    cout << endl;
    system("read -p '按任意键继续...' var");
    return 0;
}