#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    string reverseWords(string s)
    {
        // 去除多余空格
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++)
        {
            if (s[fast] != ' ')
            {
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                /*
                s[slow] = s[fast];这样写的话会在每一个非空字符都会触发一次加空格，导致同一个单词的字符之间加空格
                fast++;
                slow++;
                */
                while (fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);

        // 反转单词
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size())
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1; // 记录下一个要反转的单词的初始位置
            }
        }
        return s;
    }
};

int main()
{
    string s{"  a good  example"};
    // int k = 2;

    Solution sol;
    string ans = sol.reverseWords(s);

    for (char c : ans)
    {
        cout << c;
    }
    cout << endl;
}