#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums,int target)
    {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;//去重使用的集合set;
        sort(nums.begin(),nums.end());
        generate(0,nums,result,item,res_set,0,target);
        return result;
    };
private:
    void generate(int i,vector<int>& nums,
                  vector<vector<int>> &result,
                  vector<int> item,set<vector<int>> &res_set,
                  int sum,int target)
    {
        if(i >= nums.size() || sum > target || nums[i] > target)
        {
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if(sum == target && res_set.find(item) == res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1,nums,result,item,res_set,sum,target);
        sum -= nums[i];
        item.pop_back();
        generate(i+1,nums,result,item,res_set,sum,target);
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(1);

    vector<int> item;
    vector<vector<int>> result;
    solution s01;
    result = s01.subsetsWithDup(nums,3);
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
