#include <iostream>
#include <vector>
using namespace std;

class solution01
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(),0);
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        dp[0] = nums[0];
        int maxl = dp[0];
        for(int i = 1; i < nums.size();i++)
        {
            dp[i] = max(dp[i-1] + nums[i],nums[i]);
            if(maxl < dp[i])
            {
                maxl = dp[i];
            }
        }
        return dp[nums.size()-1];
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    solution01 s01;
    cout << s01.maxSubArray(nums);
}
