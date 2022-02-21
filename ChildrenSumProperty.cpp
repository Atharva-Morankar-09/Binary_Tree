
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

void preOrder(struct Tree* root, vector<int>& ans)
{
    if(root!=NULL)
    {
        ans.push_back(root->data);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
}

void ChildSumProperty(struct Tree* root)
{
    int child=0;
    if(root==NULL){return ;}
    if(root->left!=NULL)
    {
        child+=root->left->data;
    }
    if(root->right!=NULL)
    {
        child+=root->right->data;
    }

    if(child>root->data)
    {
        root->data=child;
    }
    else{
        if(root->left!=NULL){root->left->data=root->data;}
        if(root->right!=NULL){root->right->data=root->data;}
    }

    ChildSumProperty(root->left);
    ChildSumProperty(root->right);

    int tot=0;
    if(root->left!=NULL)
    {
        tot+=root->left->data;
    }
    if(root->right!=NULL)
    {
        tot+=root->right->data;
    }
    if(root->left!=NULL || root->right!=NULL)
    {
        root->data=tot;
    }

}
 
/*                                  50                      
                                  /    \
                                 20     3
                                / \    / \
                               40  35 63  17

                                    155                      
                                  /    \
                                 75     80
                                / \    / \
                               40  35 63  17
*/

int main()
{
    vector<int> ans;
    
    struct Tree* root = new Tree(50);
    root->left = new Tree(20);
    root->right = new Tree(3);
    root->left->left = new Tree(40);
    root->left->right = new Tree(35);
    root->right->left = new Tree(63);
    root->right->right = new Tree(17);

    cout<<"Pre-Order traversal -"<<endl;
    preOrder(root,ans);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    ChildSumProperty(root);
   
    ans.clear();
    cout<<"\nAfter function traversal -"<<endl;
    preOrder(root,ans);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;

}