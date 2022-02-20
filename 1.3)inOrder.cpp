
#include <iostream>
using namespace std;

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
    Tree(int val){
        data=val;
        left=right=NULL;
    }
};

/*        1
         / \           inOrder - 4 2 5 1 3
        2   3
       / \
      4   5
*/  

void inOrder(struct Tree* root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main()
{
    struct Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);

    cout<<"InOrder of Binary Tree-"<<endl;
    inOrder(root);

    return 0;
}
