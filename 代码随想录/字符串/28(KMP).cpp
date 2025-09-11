#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = 0;   // j代表前缀末尾
        next[0] = 0; // next[i]代表i（包括i）之前的最长的相等的前后缀长度，其实就是j
        // i代表后缀末尾
        for (int i = 1; i < s.size(); i++)
        {
            // 前后缀不相同的情况
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }

            // 前后缀相等的情况
            if (s[i] == s[j])
            {
                j++;
            }

            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;

        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j])
            {
                j++;
            }

            if (j == needle.size())
                return (i - needle.size() + 1);
        }
        return -1;
    }
};
int main()
{
    string s = {"sadbutsad"};
    string t = {"sad"};
    // int k = 2;

    Solution sol;
    int ans = sol.strStr(s, t);

    cout << ans << endl;
    // for (char c : ans)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;
}