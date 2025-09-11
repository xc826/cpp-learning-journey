#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (s.size() < p.size())
        {
            return ans;
        }

        vector<int> count(26);
        int len = p.size();
        for (int i = 0; i < len; i++)
        {
            count[p[i] - 'a']++;
        }

        for (int left = 0, right = 0; right < s.size(); right++)
        {
            count[s[right]-'a']--;
            while(count[s[right]-'a']<0)
            {
                count[s[left]-'a']++;
                left++;
            }

            if(right-left+1==len)
            {
                ans.push_back(left);
            }
        }
        return ans;

        // vector<int> cur(26);
        // for (int i = 0; i < len - 1; i++)
        // {
        //     cur[s[i] - 'a']++;
        // }

        // for (int left = 0, right = len - 1; right < s.size(); left++, right++)
        // {
        //     cur[s[right] - 'a']++;
        //     if (count == cur) // 普通数组不可以直接运用==去判断是否相等，数组名会被隐式转化为指针
        //     {
        //         ans.push_back(left);
        //     }
        //     cur[s[left] - 'a']--;
        // }
        // return ans;
    }
};

int main()
{
    string s = "cbaebabacd";
    string p = "abc";

    Solution sol;
    vector<int> ans = sol.findAnagrams(s, p);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}