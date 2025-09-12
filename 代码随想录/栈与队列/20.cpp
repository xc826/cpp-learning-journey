#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }

                char top=st.top();
                st.pop();

                if((s[i]==')'&&top!='(')||(s[i]==']'&&top!='[')||(s[i]=='}'&&top!='{'))
                {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main()
{
    string s="(}";
    Solution sol;
    bool res=sol.isValid(s);
    cout<<res<<endl;

    system("read -p '按任意键继续...' var");
    return 0;
}