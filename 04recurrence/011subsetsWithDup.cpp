#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;//去重使用的集合set;
        sort(nums.begin(),nums.end());
        result.push_back(item);
        generate(0,nums,result,item,res_set);
        return result;
    };
private:
    void generate(int i,vector<int>& nums,vector<vector<int>> &result,vector<int> item,set<vector<int>> &res_set)
    {
        if(i >= nums.size())
        {
            return;
        }
        item.push_back(nums[i]);//如果res_set集合中，无法找到item
        if(res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1,nums,result,item,res_set);
        item.pop_back();
        generate(i+1,nums,result,item,res_set);
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);

    vector<int> item;
    vector<vector<int>> result;
    solution s01;
    result = s01.subsetsWithDup(nums);
    for(int i = 0; i < result.size();i++)
    {
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j];
        }
        cout<<" ";
    }
    cout << endl;
}
