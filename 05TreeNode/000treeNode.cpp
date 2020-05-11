#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void preorder_print(TreeNode *node,int layer)
{
    if(!node)
    {
        return;
    }
    //前序遍历

    //////////////////////////////
    preorder_print(node->left,layer+1);
    //中序遍历
    for(int i = 0; i < layer;i++)
    {
        cout << "-";
    }
    cout << node->val <<endl;
    //////////////////////////
    preorder_print(node->right,layer+1);
    //后序遍历

    /////////////////////////////
}

int main()
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;

    preorder_print(&a,0);
}
