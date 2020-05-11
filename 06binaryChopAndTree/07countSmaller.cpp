#include <iostream>
#include <vector>

using namespace std;

struct BSTNode
{
    int val;
    int count;//二叉树中左子树节点个数
    BSTNode *left;
    BSTNode *right;
    BSTNode(int x):val(x),left(nullptr),right(nullptr),count(0){}
};

void BST_insert(BSTNode *node,BSTNode *insert_node,int &count_small)
{
    if(insert_node->val <= node->val)
    {
        //count_small二叉树比insert_node值小的节点个数
        node->count++;
        if(node->left)
        {
            BST_insert(node->left,insert_node,count_small);
        }
        else
        {
            node->left = insert_node;
        }
    }
    else
    {
        count_small += node->count + 1;//统计完比插入节点小的当前树节点个数后进入result
        if(node->right)
        {
            BST_insert(node->right,insert_node,count_small);
        }
        else
        {
            node->right = insert_node;
        }
    }
}

class solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> result;
        vector<BSTNode *> node_vec;
        vector<int> count;
        for(int i = nums.size()-1;i >= 0;i--)
        {
            //数组逆序排序
            node_vec.push_back(new BSTNode(nums[i]));
        }

        count.push_back(0);
        for(int i = 1;i < node_vec.size();i++)
        {
            //逆序后的二叉树查找
            //将第2（倒数：因为逆序了）到第n个节点插入到以第一个节点为根的
            //二叉排序中，再插入过程中计算每个节点的count_small
            int count_small = 0;
            BST_insert(node_vec[0],node_vec[i],count_small);
            count.push_back(count_small);//将count_small从后向前push入result
        }
        for(int i = node_vec.size()-1;i>=0;i--)
        {
            delete node_vec[i];
            result.push_back(count[i]);
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {5,-7,9,1,3,5,-2,1};
    solution s01;
    vector<int> ret = s01.countSmaller(nums);
    for(int i = 0; i < ret.size();i++)
    {
        cout << ret[i] << " ";
    }

}
