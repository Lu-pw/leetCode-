#include <iostream>
#include <vector>
using namespace std;
//µİ¹é·¨
bool binary_search(vector<int> &sort_array,int begin,int end,int target)
{
    if(begin > end) {return false;};
    int mid = (begin + end) / 2;
    if(target == sort_array[mid])
    {
        return true;
    }
    else if(target < sort_array[mid])
    {
        return binary_search(sort_array,begin,mid - 1,target);
    }
    else
    {
        return binary_search(sort_array,mid + 1,end,target);
    }
}
//Ñ­»··¨
bool binary_search_loop(vector<int> &sort_array,int target)
{
    int begin = 0;
    int end = sort_array.size() - 1;
    while(begin <= end)
    {
        int mid = (begin + end) / 2;
        if(target < sort_array[mid])
        {
            end = mid - 1;
        }else if(target > sort_array[mid])
        {
            begin = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> sort_array = {1,3,5,7,9};
    cout << boolalpha << binary_search(sort_array,0,sort_array.size()-1,3);
    cout << endl;
    cout << boolalpha << binary_search_loop(sort_array,3);
}
