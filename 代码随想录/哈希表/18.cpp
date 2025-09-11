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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < nums.size(); j++)
        {
            // 剪枝
            if (nums[j] > target && nums[j] >= 0)
                break;

            // 去重
            if (j > 0 && nums[j] == nums[j - 1])
                continue;
            for (int i = j + 1; i < nums.size(); i++)
            {
                if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0)
                    break;
                if (i > j + 1 && nums[i] == nums[i - 1])
                    continue;

                int left = i + 1, right = nums.size() - 1;
                while (right > left)
                {
                    if ((long)nums[j] + nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else if ((long)nums[j] + nums[i] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else
                    {
                        ans.push_back(vector<int>{nums[j], nums[i], nums[left], nums[right]});
                        right--;
                        left++;
                        while (right > left && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                        while (right > left && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;

    Solution sol;
    vector<vector<int>> ans = sol.fourSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    cout << endl;
    // cout << ans;
    // cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}