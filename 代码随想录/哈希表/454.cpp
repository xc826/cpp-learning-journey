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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int,int> m;
        int ans=0;
        for(int a:nums1)
        {
            for(int b:nums2)
            {
                m[a+b]++;
            }
        }
        
        for(int c:nums3)
        {
            for(int d:nums4)
            {
                if(m.find(-(c+d))!=m.end())
                {
                    ans+=m[-(c+d)];
                }   
            }
        }
        
        return ans;
    }
};

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};

    Solution sol;
    int ans = sol.fourSumCount(nums1, nums2, nums3, nums4);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << ans;
    cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}