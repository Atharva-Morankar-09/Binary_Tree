
#include<stdio.h>
#include<malloc.h>

struct Tree{
      int data;
      struct Tree* left;
      struct Tree* right;
};

/*
          1
         / \
        2   3
           / \
          4   5
*/

struct Tree* create(int data){
    struct Tree* n;
    n = (struct Tree*) malloc(sizeof(struct Tree));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int preOrder(struct Tree* p1){
      if(p1!=NULL)
      {
          printf("%d ",p1->data);
          preOrder(p1->left);
          preOrder(p1->right);
      }
}

int main()
{
    struct Tree* p1 = create(1);
    struct Tree* p2 = create(2);
    struct Tree* p3 = create(3);
    struct Tree* p4 = create(4);
    struct Tree* p5 = create(5);

    p1->left=p2;
    p1->right=p3;

    p3->left=p4;
    p3->right=p5;
    
    printf("PreOrder -\n");
    preOrder(p1);

    return 0;
}