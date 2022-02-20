
#include <iostream>
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

/*        1
         / \           postOrder - 4 5 2 3 1
        2   3
       / \
      4   5
*/  

void postOrder(struct Tree* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    struct Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);

    cout<<"PostOrder of Binary Tree-"<<endl;
    postOrder(root);

    return 0;
}
