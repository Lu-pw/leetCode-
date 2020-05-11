#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

bool BST_search(TreeNode *node,TreeNode *search_node)
{
    if(search_node->val == node->val)
    {
        return true;
    }
    if(search_node->val < node->val)
    {
        if(node->left)
        {
            return BST_search(node->left,search_node);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(node->right)
        {
            return BST_search(node->right,search_node);
        }
        else
        {
            return false;
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

    TreeNode a_search_node(3);
    cout << boolalpha << BST_search(&a,&a_search_node);


}
