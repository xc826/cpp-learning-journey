#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include<unordered_map>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int s=target-nums[i];
            if(m.find(s)!=m.end())
            {
                ans.push_back(m[s]);
                ans.push_back(i);
                return ans;
            }
            m.insert(make_pair(nums[i],i));
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 5};
    int target = 9;

    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    // cout << ans;
    cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}