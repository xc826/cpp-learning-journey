#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

class Solution {
public:
    // 方法1
    // void f(int times,int num,vector<int>& ans)
    // {
    //     for(int i=0;i<times;i++)
    //     {
    //         ans.push_back(num);
    //     }
    // }
    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    // {
    //     vector<int> ans;
    //     map<int,int> mp1,mp2;
    //     for(int i=0;i<nums1.size();i++)
    //     {
    //         mp1[nums1[i]]++;
    //     }
    //     mp2=mp1;
    //     for(int i=0;i<nums2.size();i++)
    //     {
    //         mp1[nums2[i]]--;
    //     }

    //     for(map<int,int>::iterator it=mp2.begin();it!=mp2.end();it++)
    //     {
    //         if(mp1[it->first]<0)
    //         {
    //             f(it->second,it->first,ans);
    //         }
    //         else
    //         {
    //             f(it->second-mp1[it->first],it->first,ans);
    //         }
    //     }
    //     return ans;
    // }

    // 方法2
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        map<int,int> mp;
        // 为减小空间复杂度，先遍历较短数组
        if(nums1.size()>nums2.size())
        {
            return intersect(nums2,nums1);
        }

        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(mp[nums2[i]]>0)
            {
                mp[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }


        return ans;
    }
};


int main()
{
    vector<int> nums1 = {4, 9,5};
    vector<int> nums2 = {9,4,9,8,4};

    Solution sol;
    vector<int> ans = sol.intersect(nums1, nums2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;


    system("read -p '按任意键继续...' var");
    return 0;
}