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


class solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> view;
        queue<pair<TreeNode*,int>> Q;
        if(root)
        {
            Q.push(make_pair(root,0));
        }
        while(!Q.empty())
        {
            TreeNode *node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(view.size() == depth)
            {
                view.push_back(node->val);
            }
            else
            {
                view[depth] = node->val;
            }
            if(node->left)
            {
                Q.push(make_pair(node->left,depth+1));
            }
            if(node->right)
            {
                Q.push(make_pair(node->right,depth+1));
            }
        }
        return view;
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
    vector<int> vec = s01.rightSideView(&a);
    for(int i = 0; i < vec.size();i++)
    {
        cout << vec[i] << " ";
    }
}

