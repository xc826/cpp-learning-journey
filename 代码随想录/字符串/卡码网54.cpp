#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    string replaceNumber(string s)
    {
        int count = 0;
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {
                count++;
            }
        }

        int oldIndex = s.size() - 1;
        s.resize(s.size() + count * 5);
        int newIndex = s.size() - 1;

        while (oldIndex >= 0)
        {
            if (s[oldIndex] >= '0' && s[oldIndex] <= '9')
            {
                s[newIndex--] = 'r';
                s[newIndex--] = 'e';
                s[newIndex--] = 'b';
                s[newIndex--] = 'm';
                s[newIndex--] = 'u';
                s[newIndex--] = 'n';
            }
            else
            {
                s[newIndex--] = s[oldIndex]; // 如果--操作写在这里的话，在if分支，就没有对oldIndex自减操作了
            }
            oldIndex--;
        }

        return s;
    }
};

int main()
{
    string s{"a5b"};
    // int k = 2;

    Solution sol;
    string ans = sol.replaceNumber(s);

    for (char c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}