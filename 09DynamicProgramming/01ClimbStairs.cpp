#include <iostream>
#include <vector>
using namespace std;

class solution01
{
public:
    int climbStairs(int n)
    {
        if(n == 1 || n == 2)
        {
            return n;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

class solution02
{

public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 3,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n;i++)
        {
            dp[i] = dp[i-1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    solution01 s;
    cout << s.climbStairs(6);
    solution02 s2;
    cout << s2.climbStairs(6);
    return 0;
}
