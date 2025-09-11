#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<algorithm>

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        map<string, vector<string>> rec;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            rec[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (map<string, vector<string>>::iterator it = rec.begin(); it != rec.end();it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};


int main()
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");


    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    system("read -p '按任意键继续...' var");
    return 0;
}