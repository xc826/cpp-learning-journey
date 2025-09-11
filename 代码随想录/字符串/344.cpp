#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0, right = s.size() - 1;

        while (right > left)
        {
            char temp = s[right];
            s[right] = s[left];
            s[left] = temp;

            right--;
            left++;
        }
    }
};

int main()
{
    vector<char> s{'H', 'a', 'n', 'n', 'a', 'h'};

    Solution sol;
    sol.reverseString(s);

    for (char c : s)
    {
        cout << c << " ";
    }
    cout << endl;
}