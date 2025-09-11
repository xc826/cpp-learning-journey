#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

class Solution
{
public:
    // KMP解法
    // void getNext(int *next, const string &s)
    // {
    //     int j = 0;   // j代表前缀末尾
    //     next[0] = 0; // next[i]代表i（包括i）之前的最长的相等的前后缀长度，其实就是j
    //     // i代表后缀末尾
    //     for (int i = 1; i < s.size(); i++)
    //     {
    //         // 前后缀不相同的情况
    //         while (j > 0 && s[i] != s[j])
    //         {
    //             j = next[j - 1];
    //         }

    //         // 前后缀相等的情况
    //         if (s[i] == s[j])
    //         {
    //             j++;
    //         }

    //         next[i] = j;
    //     }
    // }

    // bool repeatedSubstringPattern(string s)
    // {
    //     vector<int> next(s.size());
    //     getNext(&next[0], s);

    //     if (s.size() % (s.size() - next[s.size() - 1])==0)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    // 移动匹配法
    bool repeatedSubstringPattern(string s)
    {
        string ss = s + s; // 不能用s.append(s),因为这会修改原来的s
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        if (ss.find(s) != ss.npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 暴力解法
    //  bool repeatedSubstringPattern(string s)
    //  {
    //      int n=s.size();
    //      for(int i=1;i<=n/2;i++)
    //      {
    //          if(n%i==0)
    //          {
    //              bool match=true;
    //              for(int j=i;j<n;j++)
    //              {
    //                  if(s[j]!=s[j-i])
    //                  {
    //                      match=false;
    //                      break;
    //                  }
    //              }
    //              if(match)
    //              {
    //                  return true;
    //              }
    //          }
    //      }
    //      return false;

    // }
};
int main()
{
    string s = {"aba"};
    string t = {"sad"};
    // int k = 2;

    Solution sol;
    bool ans = sol.repeatedSubstringPattern(s);

    cout << ans << endl;
    // for (char c : ans)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;
}