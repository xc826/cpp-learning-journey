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
    int getsum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10); // 先求最低位数字平方
            n /= 10;                    // 去掉最低位
        }
        return sum;
    }

    bool isHappy(int n)
    {
        set<int> s;
        while (1)
        {
            int sum = getsum(n);
            if (sum == 1)
            {
                return true;
            }

            if (s.find(sum) != s.end())
            {
                return false;
            }
            else
            {
                s.insert(sum);
            }
            n = sum;
        }
        }
};

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    int n = 19;

    Solution sol;
    bool ans = sol.isHappy(n);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    cout << ans;
    cout << endl;

    system("read -p '按任意键继续...' var");
    return 0;
}