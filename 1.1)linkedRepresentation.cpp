
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};

  /*      1
         / \
        2   3
       / \
      4   5
  */  
int main()
{
    // struct Node* p1 = new Node(1);
    // struct Node* p2 = new Node(2);
    // struct Node* p3 = new Node(3);
    // struct Node* p4 = new Node(4);
    // struct Node* p5 = new Node(5);

    // or

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right =  new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    // p1->left=p2;
    // p1->right=p3;
    // p2->left=p4;
    // p2->right=p5;
    return 0;
}
