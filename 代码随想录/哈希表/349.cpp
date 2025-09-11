#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        /* 利用集合set
        set<int> res;
        set<int> s;
        for (int i = 0; i < nums1.size(); i++)
        {
            s.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (s.find(nums2[i]) != s.end())
            {
                res.insert(nums2[i]);
            }
        }
        // return vector<int> ans(res.begin(),res.end());

        vector<int> ans(res.begin(),res.end());
        return ans;//C++ 中，返回一个临时对象时，不需要显式指定变量名
        */

        // 利用数组array

        set<int> s;
        int hash[1005];
        for (int i = 0; i < nums1.size(); i++)
        {
            hash[nums1[i]] = 1;
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (hash[nums2[i]] == 1)
            {
                s.insert(nums2[i]);
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution sol;
    vector<int> ans = sol.intersection(nums1, nums2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}