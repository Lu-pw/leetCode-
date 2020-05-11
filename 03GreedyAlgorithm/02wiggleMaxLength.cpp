#include <iostream>
#include <vector>

using namespace std;

class solution01
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if(nums.size() <2)
        {
            return nums.size();
        }
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int state = BEGIN;
        int max_length = 0;
        for(int i = 1; i < nums.size();i++)
        {
            switch(state)
            {
            case BEGIN:
                if(nums[i] > nums[i-1])
                {
                    state = UP;
                    max_length++;
                }
                else if(nums[i] < nums[i-1])
                {
                    state = DOWN;
                    max_length++;
                }
                break;
            case UP:
                if(nums[i] < nums[i-1])
                {
                    state = DOWN;
                    max_length++;
                }
                break;
            case DOWN:
                if(nums[i] > nums[i-1])
                {
                    state = UP;
                    max_length++;
                }
                break;
            }
        }
        return max_length;
    }
};

int main()
{
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    solution01 s01;
    cout << s01.wiggleMaxLength(nums);
}
