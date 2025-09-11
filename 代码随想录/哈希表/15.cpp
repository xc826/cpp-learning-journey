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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    ans.push_back(vector<int>{nums[i], nums[left], nums[right]});
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

        return ans;
    }
};
int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

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