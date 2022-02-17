#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data)
{
    struct Node* n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main()
{
    struct Node* p;
    struct Node* p1;
    struct Node* p2;
    p = createNode(2);
    p1 = createNode(4);
    p2 = createNode(6);
    p->left=p1;
    p->right=p2;
    return 0;
}