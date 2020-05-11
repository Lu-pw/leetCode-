#include <iostream>
#include <vector>

using namespace std;

//哈希表排序，使用数组的下标对正整数排序
//哈希表的长度，需要大于最大待排序数字；
int main()
{
    int random[10] = {999,1,444,7,20,9,1,3,7,7};
    int hash_map[1000] = {0};
    for(int i = 0;i < 10;i++)
    {
        hash_map[random[i]]++;
    }
    for(int i = 0;i < 1000;i++)
    {
        for(int j = 0;j < hash_map[i];j++)
        {
            cout << i << "  ";
        }
    }
    //时间复杂度O（表长+n）n为元素个数
}
