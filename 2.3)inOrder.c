
#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

/*
          1
         / \
        2   3
           / \
          4   5
*/

struct Node* createNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void inOrder(struct Node* p){
    if(p!=NULL){
        inOrder(p->left);
        printf("%d ", p->data);
        inOrder(p->right);
    }
}

int main()
{
    struct Node* p1 = createNode(1);
    struct Node* p2 = createNode(2);
    struct Node* p3 = createNode(3);
    struct Node* p4 = createNode(4);
    struct Node* p5 = createNode(5);

    p1->left = p2;
    p1->right = p3;

    p3->left = p4;
    p3->right = p5;

    printf("InOrder -\n");
    inOrder(p1);
    return 0;
}
