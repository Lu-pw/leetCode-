#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};


class solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root,int sum)
    {
        vector<int> result;
        vector<vector<int>> vec;
        stack<TreeNode *> stk;
        preorder_print(root,stk);

        while(!stk.empty())
        {
            result.clear();
            int now = 0;
            findpath(stk.top(),now,sum,result,vec);
            stk.pop();
        }
        return vec;
    }
    void preorder_print(TreeNode *root,stack<TreeNode*> &stk)
    {
        if(!root)
        {
            return;
        }
        stk.push(root);
        preorder_print(root->left,stk);
        preorder_print(root->right,stk);
    }
    void findpath(TreeNode *root,int &now,int sum,vector<int> &result,vector<vector<int>> &vec)
    {
        if(now > sum || !root)
        {
            return;
        }
        now += root->val;
        result.push_back(root->val);
        if(now == sum)
        {
            vec.push_back(result);
        }
        findpath(root->left,now,sum,result,vec);
        findpath(root->right,now,sum,result,vec);
    }
};

class solution02
{
public:
    vector<vector<int>> pathSum(TreeNode* root,int sum)
    {
        vector<vector<int>> result;
        vector<int> path;
        int path_value = 0;
        preorder(root,path_value,sum,path,result);
        return result;
    }
private:
    void preorder(TreeNode *node,int &path_value,int sum,
                  vector<int> &path,
                  vector<vector<int>> &result)
    {
        if(!node)
        {
            return;
        }
        path_value += node->val;
        path.push_back(node->val);
        if(path_value == sum)
        {
            result.push_back(path);
        }
        preorder(node->left,path_value,sum,path,result);
        preorder(node->right,path_value,sum,path,result);
        path_value -= node->val;
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
    vector<vector<int>> vec = s01.pathSum(&a,6);
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] <<" ";
        }
        cout << endl;
    }

    solution02 s02;
    vec = s02.pathSum(&a,6);
    for(int i = 0; i < vec.size(); i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] <<" ";
        }
        cout << endl;
    }
}
