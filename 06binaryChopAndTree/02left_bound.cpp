#include <iostream>
#include <vector>

using namespace std;

int left_bound(vector<int> &nums,int target)
{
    int begin = 0;
    int end = nums.size() - 1;
    while(begin <= end)
    {
        int mid = (begin + end) / 2;
        if(target == nums[mid])
        {
            if(mid == 0 || nums[mid - 1] < target)
            {
                return mid;
            }
            end = mid - 1;
        }
        else if(target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }
    return -1;
}

int right_bound(vector<int> nums,int target)
{
    int begin = 0;
    int end = nums.size() - 1;
    while(begin < end)
    {
        int mid = (begin + end) / 2;
        if(target == nums[mid])
        {
            if(mid == nums.size() - 1 || nums[mid +1] > target)
            {
                return mid;
            }
            begin = mid + 1;
        }
        else if(target < nums[mid])
        {
            end = mid - 1;
        }
        else
        {
            begin = mid + 1;
        }
    }
}

int main()
{
    vector<int> nums = {5,7,7,8,8,8,8,10};
    cout << left_bound(nums,8) << " " << right_bound(nums,8);
}
