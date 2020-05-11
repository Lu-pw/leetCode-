#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};



class solution
{
public:
    void *flatten(TreeNode *root)
    {
        vector<TreeNode*> node_vec;
        preorder(root,node_vec);
        for(int i = 1;i < node_vec.size();i++)
        {
            node_vec[i-1]->left = node_vec[i];
            node_vec[i-1]->right = nullptr;
        }
    }
    void preorder(TreeNode *node,vector<TreeNode*> &node_vec)
    {
        if(!node)
        {
            return;
        }
        node_vec.push_back(node);
        preorder(node->left,node_vec);
        preorder(node->right,node_vec);
    }
};

class solution02
{
    public:
    void flatten(TreeNode *root)
    {
        TreeNode *last = NULL;
        preorder(root,last);
    }

    void preorder(TreeNode *node,TreeNode *&last)
    {
        if(!node)
        {
            return;
        }
        if(!node->left && !node->right)
        {
            last = node;
            return;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *left_last = NULL;
        TreeNode *right_last = NULL;
        if(left)
        {
            preorder(left,left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right)
        {
            preorder(right,right_last);
            if(left_last)
            {
                left_last->right = right;
            }
            last = right_last;
        }
    }
};

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

    solution s01;
    s01.flatten(&a);
    TreeNode *p = &a;
    while(p)
    {
        cout<< p->val;
        p = p->left;
    }
    cout << endl;



    TreeNode h(1);
    TreeNode i(2);
    TreeNode j(3);
    TreeNode k(4);
    TreeNode m(5);
    TreeNode n(6);
    h.left = &i;
    h.right = &j;
    i.left = &k;
    j.left = &m;
    j.right = &n;
    solution02 s02;
    s02.flatten(&h);

    TreeNode *pp = &h;
    while(pp)
    {
        cout<< pp->val;
        pp = pp->right;
    }
}
