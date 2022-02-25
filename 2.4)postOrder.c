
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

struct Node* creaeNode(int data){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    
    return p;
}

void postOrder(struct Node* p){
    if(p!=NULL){
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ",p->data);
    }
}

int main()
{
    struct Node* p1 = creaeNode(1);
    struct Node* p2 = creaeNode(2);
    struct Node* p3 = creaeNode(3);
    struct Node* p4 = creaeNode(4);
    struct Node* p5 = creaeNode(5);

    p1->left = p2;
    p1->right = p3;

    p3->left = p4;
    p3->right = p5;

    printf("PostOrder -\n");
    postOrder(p1);

    return 0;
}
