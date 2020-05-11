#include <queue>
#include <iostream>

using namespace std;

class MedianFinder
{
public:
    void addNum(int num)
    {
        if(big_heap.empty())
        {
            big_heap.push(num);
            return;
        }
        if(big_heap.size() == small_heap.size())
        {
            if(big_heap.top() > num)
            {
                big_heap.push(num);
            }
            else
            {
                small_heap.push(num);
            }
        }
        else if(big_heap.size() > small_heap.size())
        {
            if(num > big_heap.top())
            {
                small_heap.push(num);
            }
            else
            {
                small_heap.push(big_heap.top());
                big_heap.pop();
                big_heap.push(num);
            }
        }
        else
        {
            if(num < small_heap.top())
            {
                big_heap.push(num);
            }
            else
            {
                big_heap.push(small_heap.top());
                small_heap.pop();
                small_heap.push(num);
            }
        }
    }


    double findMedian()
    {
        if(small_heap.size() == big_heap.size())
        {
            return (small_heap.top() + big_heap.top()) / 2;
        }
        else if(small_heap.size() < big_heap.size())
        {
            return big_heap.top();
        }
        else
        {
            return small_heap.top();
        }
    }
private:
    priority_queue<int,vector<int>,greater<int>> small_heap;
    priority_queue<int,vector<int>,less<int>> big_heap;
};


int main()
{
    MedianFinder M;
    int test[] = {6,10,2,3,5,99,62};
    for(int  i = 0; i < 7; i++)
    {
        M.addNum(test[i]);
    }

    cout << M.findMedian() << endl;


}
