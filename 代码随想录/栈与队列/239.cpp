#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    // 创建一个单调队列以维护窗口的元素，随着窗口的移动，队列中的元素也一进一出
    class mydeque
    {
    public://class默认情况下权限为私密，struct默认情况下权限是公共
        deque<int> deq;

        void pop(int val)
        {
            if (!deq.empty() && deq.front() == val)
            {
                deq.pop_front();
            }
        }

        void push(int val)
        {
            while (!deq.empty() && val > deq.back())
            {
                deq.pop_back();
            }
            deq.push_back(val);
        }

        int get_max()
        {
            return deq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        mydeque deq;
        vector<int> res; //存储结果

        for(int i=0;i<k;i++)
        {
            deq.push(nums[i]);//自创队列要记得设置权限是public，不然这里不能访问
        }
        res.push_back(deq.get_max());

        for(int i=k;i<nums.size();i++)
        {
            deq.pop(nums[i-k]);//其中逻辑在自创类中已经实现
            deq.push(nums[i]);
            res.push_back(deq.get_max());
        }
        return res;

    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = sol.maxSlidingWindow(nums, k);
    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;
}