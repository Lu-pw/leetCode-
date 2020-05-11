#include <vector>
#include <iostream>

using namespace std;

class solution
{
public:
    int search(vector<int> &nums,int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end)
        {
            int mid = (begin + end) / 2;
            if(target == nums[mid])
            {
                return mid;
            }
            else if(target < nums[mid])
            {
                if(nums[begin] < nums[mid])
                {
                    if(target >= nums[begin])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        begin = mid + 1;
                    }
                }
                else if(nums[begin] > nums[end])
                {
                    end = mid - 1;
                }
                else if(nums[begin] == nums[mid])
                {
                    begin = mid + 1;
                }
            }
            else if(target > nums[mid])
            {
                if(nums[begin] < nums[mid])
                {
                    begin = mid + 1;
                }
                else if(nums[begin] > nums[mid])
                {
                    if(target >= nums[begin])
                    {
                        end = mid - 1;
                    }
                    else
                    {
                        begin = mid + 1;
                    }
                }
                else if(nums[begin] == nums[mid])
                {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {7,9,10,1,2,5,6};
    solution s01;
    cout << s01.search(nums,2);
}
