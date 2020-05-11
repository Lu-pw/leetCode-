#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
public:
    int findKthLargest(std::vector<int>& nums,int k)
    {//��С�ѣ���һ���ն˽ڵ��ֵ�����������ӽڵ�����ӽڵ��ֵ
        priority_queue<int,std::vector<int>,greater<int>> small_heap;
        for(int i = 0;i < nums.size();i++)
        {
            if(i < k)
            {
                small_heap.push(nums[i]);
            }
            else if(nums[i] > small_heap.top())
            {
                small_heap.pop();
                small_heap.push(nums[i]);
            }
        }
        return small_heap.top();
    }
};

int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    solution s;
    cout << s.findKthLargest(nums,2);
}
