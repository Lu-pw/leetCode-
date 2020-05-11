//https://leetcode-cn.com/problems/matchsticks-to-square/
//Ã‚∫≈473

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
public:
    bool makesquare(vector<int>& nums)
    {
        if(nums.size() < 4)
        {
            return false;
        }
        int target = 0;
        for(int i = 0;i < nums.size();i++)
        {
            target += nums[i];
        }
        if(target % 4 != 0)
        {
            return false;
        }
        sort(nums.rbegin(),nums.rend());
        target = target/4;
        int bucket[4] = {0};
        return generate(0,nums,target,bucket);
    }
private:
    bool generate(int i,vector<int> &nums,int target,int bucket[])
    {
        if(i >= nums.size())
        {
            return bucket[0] == target && bucket[1] == target
            &&bucket[2] == target && bucket[2] == target;
        }
        for(int j = 0;j < 4;j++)
        {
            if(bucket[j] + nums[i] > target)
            {
                continue;
            }
            bucket[j] += nums[i];
            if(generate(i+1,nums,target,bucket))
            {
                return true;
            }
            bucket[j] -= nums[i];
        }
        return false;
    }
};

class solution02
{
public:
    bool makesquare(vector<int>& nums)
    {
        if(nums.size() < 4)
        {
            return false;
        }
        int target = 0;
        for(int i = 0;i < nums.size();i++)
        {
            target += nums[i];
        }
        if(target % 4)
        {
            return false;
        }
        target = target / 4;
        vector<int> ok_subset;
        vector<int> ok_half;
        int all = 1 << nums.size();
        for(int i = 1;i < all;i++)
        {
            int sum = 0;
            for(int j =0;j < nums.size();j++)
            {
                if(i&(1<<j))
                {
                    sum += nums[j];
                }
            }
            if(sum == target)
            {
                ok_subset.push_back(i);
            }
        }
        for(int i = 0;i < ok_subset.size();i++)
        {
            for(int j = i+1;j < ok_subset.size();j++)
            {
                if((ok_subset[i]&ok_subset[j])==0)
                {
                    ok_half.push_back(ok_subset[i] | ok_subset[j]);
                }
            }
        }
        for(int i = 0;i < ok_half.size();i++)
        {
            for(int j = i + 1;j < ok_half.size();j++)
            {
                if((ok_half[i] &ok_half[j]) == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main()
{
    vector<int> nums = {1,1,2,2,2};
    solution s01;
    cout << boolalpha << s01.makesquare(nums)<<endl;
    solution02 s02;
    cout << boolalpha << s02.makesquare(nums)<<endl;
    for(int i = 0; i < 4;i++)
    {
        cout <<(1<<i) <<" ";
    }

}
