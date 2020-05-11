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
    TreeNode* lowestCommonAncestor(TreeNode *node,TreeNode *p,TreeNode *g)
    {
        vector<TreeNode*> path;
        vector<TreeNode*> node_p_path;
        vector<TreeNode*> node_q_path;
        int finish = 0;
        preorder(node,p,path,node_p_path,finish);
        path.clear();
        finish = 0;
        preorder(node,g,path,node_q_path,finish);
        int path_len = 0;
        if(node_p_path.size() < node_q_path.size())
        {
            path_len = node_p_path.size();
        }
        else
        {
            path_len = node_q_path.size();
        }
        TreeNode *re;
        for(int i = 0; i < path_len;i++)
        {
            if(node_p_path[i] == node_q_path[i])
            {
                re = node_p_path[i];
            }
        }
        return re;
    }

    void preorder(TreeNode *node,TreeNode *search,
                  vector<TreeNode*> &path,
                  vector<TreeNode*> &result,int &finish)
    {
        if(!node || finish == 1)
        {
            return;
        }
        path.push_back(node);
        if(node == search)
        {
            finish = 1;
            result = path;
        }
        preorder(node->left,search,path,result,finish);
        preorder(node->right,search,path,result,finish);
        path.pop_back();
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
    TreeNode *re = s01.lowestCommonAncestor(&a,&e,&f);
    cout << re->val;
}
