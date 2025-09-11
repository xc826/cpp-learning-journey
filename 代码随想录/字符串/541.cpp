#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
        {
            if (i + k <= s.size())
            {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else
            {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main()
{
    string s{"abcdefg"};
    int k = 2;

    Solution sol;
    string ans=sol.reverseStr(s, k);

    for (char c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}