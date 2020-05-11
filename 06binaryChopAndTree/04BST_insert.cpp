#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void BST_insert(TreeNode *node,TreeNode *insert_node)
{
    if(insert_node->val < node->val)
    {
        if(node->left)
        {
            BST_insert(node->left,insert_node);
        }
        else
        {
            node->left = insert_node;
        }
    }
    else
    {
        if(node->right)
        {
            BST_insert(node->right,insert_node);
        }
        else
        {
            node->right = insert_node;
        }
    }
}

void preorder(TreeNode *root,int layer)
{
    if(!root)
    {
        return;
    }
    for(int i = 0; i < layer;i++)
    {
        cout << "--";
    }
    cout << root->val << endl;
    preorder(root->left,layer+1);
    preorder(root->right,layer+1);
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

    TreeNode a_insert_node(3);
    BST_insert(&a,&a_insert_node);
    preorder(&a,0);

}
