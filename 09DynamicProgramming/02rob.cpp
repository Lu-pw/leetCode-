#include <iostream>
#include <vector>
using namespace std;

class solution01
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1,0);
        if(nums.size() == 0)
        {
            return 0;
        }
        dp[1] = nums[0];
        if(nums.size() == 1)
        {
            return dp[1];
        }
        dp[2] = max(nums[0],nums[1]);
        for(int i = 3;i <= nums.size();i++)
        {
            dp[i] = max(dp[i-1],dp[i-2] + nums[i-1]);
        }
        return dp[nums.size()];
    }
};

int main()
{
    solution01 s01;
    vector<int> m = {5,2,6,3,1,7};
    cout << s01.rob(m);
}
