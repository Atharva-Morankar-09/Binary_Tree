
#include<iostream>
#include<vector>
using namespace std;

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
    Tree(int val)
    {
        data=val;
        left=right=NULL;
    }
};

/*
            1
           / \
          2   3
         / \   \ 
        4   5   7
           /
          6   
*/

void preOrder(struct Tree* root, vector<int>& ans)
{
    if(root==NULL)
    {
        return;
    }
    ans.push_back(root->data);
    preOrder(root->left,ans);
    preOrder(root->right,ans);
}

bool path(struct Tree* root, vector<int>& ans, int x)
{
    if(root==NULL){return false;}

    ans.push_back(root->data);

    if(root->data==x){return true;}

    if(path(root->left,ans,x) || path(root->right,ans,x))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

int main()
{
    vector<int> ans;
    int target;
    cout<<"Enter the target - ";
    cin>>target;
    struct Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->left->right->left = new Tree(6);
    root->right->right = new Tree(7);

    // cout<<"Pre Order Traversal is"<<endl;
    // preOrder(root,ans);

    cout<<"Root to Node path is :-"<<endl;
    path(root,ans,target);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
