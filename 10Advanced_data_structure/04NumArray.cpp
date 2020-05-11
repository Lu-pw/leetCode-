#include <iostream>
#include <vector>

//https://leetcode.com/problems/range-sum-query-mutable/description/
//题号307
using namespace std;

//线段树构造
void build_segment_tree(vector<int> &value,vector<int>& nums,
                        int pos,int left,int right)
{
    if(left == right)
    {
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right) / 2;
    build_segment_tree(value,nums,pos * 2 +1,left,mid);
    build_segment_tree(value,nums,pos * 2 + 2,mid + 1,right);
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}
//线段树遍历
void print_segment_tree(vector<int> &value,
                        int pos,int left,int right,int layer)
{
    for(int i = 0; i < layer; i++)
    {
        cout << "---";
    }
    cout << "["<<left << "," << right<<"]" << ": " << pos << ":" << value[pos] <<endl;
    if(left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    print_segment_tree(value,pos * 2 + 1,left,mid,layer + 1);
    print_segment_tree(value,pos * 2 + 2,mid + 1,right,layer + 1);
}


int sum_range_segment_tree(vector<int> &value,int pos,int left,
                           int right,int qleft, int qright)
{
    if(qleft > right || qright < left)
    {
        return 0;
    }
    if(qleft <= left && qright >= right)
    {
        return value[pos];
    }
    int mid = (left + right) / 2;
    return sum_range_segment_tree(value,pos * 2+ 1,left,mid,qleft,qright) +
           sum_range_segment_tree(value,pos * 2+2,mid + 1,right,qleft,qright);
}

void update_segment_tree(vector<int> &value,int pos,int left,
                         int right,int index,int new_value)
{
    if(left == right && left == index)
    {
        value[pos] = new_value;
        return;
    }
    int mid = (left + right) / 2;
    if(index <= mid)
    {
        update_segment_tree(value,pos * 2+ 1,left,mid,index,new_value);
    }
    else
    {
        update_segment_tree(value,pos * 2 + 2,mid + 1,
                            right,index,new_value);
    }
    value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
}

class NumArray
{
public:
    NumArray(vector<int> nums)
    {
        if(nums.size() == 0)
        {
            return;
        }
        int n = nums.size() * 4;
        for(int i = 0; i < n; i++)
        {
            _value.push_back(0);
        }
        build_segment_tree(_value,nums,0,0,nums.size() - 1);
        _right_end = nums.size() - 1;
    }
    void update(int i,int val)
    {
        update_segment_tree(_value,0,0,_right_end,i,val);
    }
    int sumRange(int i,int j)
    {
        return sum_range_segment_tree(_value,0,0,_right_end,i,j);
    }
private:
    vector<int> _value;
    int _right_end;
};


/////////////////////////////////////////
//class NumArray
//{
//public:
//    NumArray(vector<int> &nums)
//    {
//        trees=vector<int>(nums.size()*4,0);
//        int i;
//        tempSum=0;
//        size=nums.size();
//        for(i=0; i<size; i++)
//            build(trees,i,nums[i],0,nums.size()-1,1);
//    }    void build(vector<int>&trees,int index,int value,int left,int right,int root)
//    {
//        if(left==right)
//        {
//            trees[root]=value;
//            return;
//        }
//        int middle=(left+right)/2;
//        if(index<=middle)
//            build(trees,index,value,left,middle,root*2);
//        else
//            build(trees,index,value,middle+1,right,root*2+1);
//        trees[root]=trees[root*2]+trees[root*2+1];
//    }     void update(int i, int val)
//    {
//        build(trees,i,val,0,size-1,1);
//    }     int calculate(int tl,int tr,int cl,int cr,int root)
//    {
//        int middle=(cl+cr)/2;
//        if(tl<=cl&&cr<=tr)
//            return trees[root];
//        if(middle<tl)
//            return calculate(tl,tr,middle+1,cr,root*2+1);
//        else if(tr<=middle)
//            return calculate(tl,tr,cl,middle,root*2);
//        else
//            return calculate(tl,middle,cl,middle,root*2)+calculate(middle+1,tr,middle+1,cr,root*2+1);
//    }     int sumRange(int i, int j)
//    {
//        return calculate(i,j,0,size-1,1);
//    } private:
//    vector<int> trees;
//    int tempSum,size;
//};

////////////////////////////////////

int main()
{
    vector<int> nums;
    for(int i = 0; i < 6; i++)
    {
        nums.push_back(i);
    }
    vector<int> value;
    for(int i = 0; i < 24; i++)
    {
        value.push_back(0);
    }
    build_segment_tree(value,nums,0,0,nums.size() - 1);
    printf("segment_tree:\n");
    print_segment_tree(value,0,0,nums.size() - 1,0);
    int sum_range = sum_range_segment_tree(value,0,0,nums.size() - 1, 2,4);
    printf("sum_range[2,5] = %d\n",sum_range);
    update_segment_tree(value,0,0,nums.size() - 1,2,10);
    printf("segment_tree\n");
    print_segment_tree(value,0,0,nums.size()-1,0);
}
