#include <iostream>
#include <vector>

using namespace std;

class solution01
{
public:
    bool canJump(vector<int>& nums)
    {
        vector<int> index;//最远可跳至的位置
        for(int i = 0;i < nums.size();i++)
        {
            index.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = index[0];
        while(jump < nums.size() && jump <= max_index)
        {
            if(max_index < index[jump])
            {
                max_index = index[jump];
            }
            jump++;
        }
        if(jump == nums.size())
        {
            return true;
        }
        return false;
    }
};

class solution02
{
public:
    int canJump(vector<int> nums)
    {
        if(nums.size() == 2)
        {
            return 0;
        }
        int current_max_index = nums[0];//当前可到达最远位置
        int pre_max_max_index = nums[0];//各个位置可到达最远位置
        int jump_min = 1;
        for(int i = 1;i < nums.size();i++)
        {
            if(i > current_max_index)//若无法向前移动了，才进行跳跃
            {
                current_max_index = pre_max_max_index;
                jump_min++;
            }
            if(pre_max_max_index < nums[i] + i)
            {
                pre_max_max_index = nums[i] + i;
            }
        }
        return jump_min;
    }
};

int main()
{
    solution01 s01;
    vector<int> nums = {1,7,2,5,6};
    cout << boolalpha << s01.canJump(nums) << endl;

    solution02 s02;
    cout << s02.canJump(nums);
}
