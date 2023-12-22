#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
    struct node *next;
};
  
int main()
{
   struct node *root;
   root=(struct node*)malloc(sizeof(struct node));
   root->x=10;
   root->next=(struct node*)malloc(sizeof(struct node));
   root->next->x=20;
   struct node *iter;
   iter=root;
   printf("%d ",iter->x);
   iter=iter->next;
   printf(" %d",iter->x);

   return 0;
} 
