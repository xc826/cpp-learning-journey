#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    string reverseCharacter(string s, int k)
    {
        reverse(s.begin(), s.end()); // 整体反转

        reverse(s.begin(), s.begin() + k); // 先反转前k个

        reverse(s.begin() + k, s.end()); // 在反转后面一部分

        return s;
    }
};

int main()
{
    string s{"abcdefg"};
    int k = 2;

    Solution sol;
    string ans = sol.reverseCharacter(s, k);

    for (char c : ans)
    {
        cout << c << " ";
    }
    cout << endl;
}