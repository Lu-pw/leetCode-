#include <iostream>
#include <vector>

using namespace std;

class solution01
{
public:
    int coinChange(vector<int> &coins,int amount)
    {
        vector<int> dp;
        for(int i = 0;i <= amount;i++)
        {
            dp.push_back(-1);
        }
        dp[0] = 0;
        for(int i = 1;i <= amount;i++)
        {
            for(int j= 0;j < coins.size();j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1)
                {
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1)
                    {
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main()
{
    vector<int> coins = {1,2,5,7,10};
    int amount = 14;
    solution01 s01;
    cout << s01.coinChange(coins,amount);
}
