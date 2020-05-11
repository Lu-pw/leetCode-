#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> big_heap2;//默认最大堆
    priority_queue<int,std::vector<int>,greater<int>> small_heap;//最小堆构造方法
    priority_queue<int,std::vector<int>,less<int>> big_heap;//最大堆构造
    if(big_heap.empty())
    {
        cout << "big_heap is empty!" << endl;
    }
    int test[] = {6,10,2,3,5,99,62};
    for(int  i = 0; i < 7;i++)
    {
        big_heap.push(test[i]);
    }
    cout << "big_heap.top() = " << big_heap.top() << endl;
    big_heap.push(1000);
    cout << "big_heap.top() = " << big_heap.top() << endl;
    for(int i = 0; i < 3; i++)
    {
        big_heap.pop();
    }
    cout << "big_heap.top() = " << big_heap.top() << endl;
 }
