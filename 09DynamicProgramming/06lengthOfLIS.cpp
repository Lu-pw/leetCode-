#include <iostream>
#include <vector>
using namespace std;

class solution01
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if(nums.size() == 0)return 0;
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int LIS = 1;
        for(int i = 1;i < nums.size();i++)
        {
            dp[i] = 1;//以i为结尾的最长子序列
            for(int j = 0;j < i;j++)
            {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if(LIS < dp[i])
            {
                LIS = dp[i];
            }
        }
        return LIS;
    }
};


class solution02
{
public:
    int lengthOfLis(vector<int> & nums)
    {
        if(nums.size() == 0) return 0;
        vector<int> stk;
        stk.push_back(nums[0]);
        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] > stk.back())
            {
                stk.push_back(nums[i]);
            }else
            {
                for(int j = 0;j < stk.size();j++)
                {
                    if(stk[j] >= nums[i])
                    {
                        stk[j] = nums[i];
                        break;
                    }
                }
            }
        };
        return stk.size();
    }
};
int main()
{
    vector<int> nums = {1,3,2,3,1,4};
    solution01 s01;
    cout << s01.lengthOfLIS(nums);
    solution02 s02;
    cout <<s02.lengthOfLis(nums);
}
