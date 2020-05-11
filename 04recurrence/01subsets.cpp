#include <iostream>
#include <vector>

using namespace std;

void generate(int i,vector<int> &nums,vector<int> &item,vector<vector<int>> &result)
{
    if(i >= nums.size())
    {
        return;
    }
    item.push_back(nums[i]);
    result.push_back(item);
    generate(i+1,nums,item,result);
}

//选子集法
class solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> item;
        result.push_back(item);
        generate(0,nums,item,result);
        return result;
    }

private:
    void generate(int i,vector<int> &nums,vector<int> &item,vector<vector<int>> &result)
    {
        if(i >= nums.size())//递归结束条件
        {
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1,nums,item,result);
        item.pop_back();
        generate(i+1,nums,item,result);
    }
};



//位运算法
class solution02
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        int all_set = 1 << nums.size();//1<<n即为2^n
        for(int i = 0; i < all_set;i++)//遍历所有集合
        {
            vector<int> item;
            for(int j = 0;j < nums.size();j++)
            {
                if(i & (1 << j))//构造数字i代表的集合，各元素存储至item
                {
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};


int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<int> item;
    vector<vector<int>> result;

    for(int i = 0;i < nums.size();i++)
    {
        item.push_back(nums[i]);
        result.push_back(item);
    }

    for(int i = 0; i < result.size();i++)
    {
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j];
        }
        cout<<" ";
    }
    cout << endl;

    item.clear();
    result.clear();
    generate(0,nums,item,result);
    for(int i = 0; i < result.size();i++)
    {
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j];
        }
        cout<<" ";
    }
    cout << endl;

    solution s01;
    result = s01.subsets(nums);
    for(int i = 0; i < result.size();i++)
    {
        for(int j = 0;j < result[i].size();j++)
        {
            cout << result[i][j];
        }
        cout<<" ";
    }
    cout << endl;

    result.clear();
    solution02 s02;
    result = s02.subsets(nums);
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
