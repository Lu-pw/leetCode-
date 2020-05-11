#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void BFS_print(TreeNode* root)
{
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        TreeNode *node = Q.front();
        Q.pop();
        cout << node->val;
        if(node->left)
        {
            Q.push(node->left);
        }
        if(node->right)
        {
            Q.push(node->right);
        }
    }
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

    BFS_print(&a);
}
