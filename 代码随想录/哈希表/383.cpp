#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        unordered_map<char, int> m;

        for (int i = 0; i < magazine.size(); i++)
        {
            m[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            m[ransomNote[i]]--;
            if (ransomNote[i] < 0)
            {
                return false;
            }
        }

        // 可以合并在上面的for循环里面
        // for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        // {
        //     if (it->second < 0)
        //     {
        //         return false;
        //     }
        // }
        return true;
    }
};

int main()
{
    string s = "aa", t = "aab";

    Solution sol;
    bool ans = sol.canConstruct(s, t);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << ans;
    cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}