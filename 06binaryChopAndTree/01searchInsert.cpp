#include <vector>
#include <iostream>

using namespace std;

class solution
{
public:
    int searchInsert(vector<int> &nums,int target)
    {
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while(index == -1)
        {
            int mid = (begin + end) /2;
            if(target == nums[mid])
            {
                index = mid;
            }
            else if(target < nums[mid])
            {
                if(mid == 0 || target > nums[mid - 1])
                {
                    return mid;
                }
                end = mid - 1;
            }
            else
            {
                if(mid == nums.size() - 1 || target < nums[mid + 1])
                {
                    return mid + 1;
                }
                begin = mid + 1;
            }
        }
        return index;
    }
};

int main()
{
    vector<int> nums = {1,3,5,7};
    solution s01;
    for(int i = 0; i < 8;i++)
    {
        cout<<"index = " << i << " res = " << s01.searchInsert(nums,i) <<endl;
    }
}
