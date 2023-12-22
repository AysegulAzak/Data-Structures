#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *BTREE;

void inorder(BTREE root) {
	if(root!=NULL) {
		inorder(root->left);
		printf("%4d", root->data);
		inorder(root->right);
	}
}

BTREE insert(BTREE root, int x) {
	if(root==NULL) 
	{
		BTREE new = malloc(sizeof(BTREE));
		new->left=new->right=NULL;
		new->data=x;
		return new;
	}
    if(root->data<x) {
	root->right=insert(root->right, x);
	return root;
}
else if(root->data>x) {
	root->left=insert(root->left, x);
}
return root;
}

void traverse(BTREE root) {
	if(root==NULL)
	return;
	printf("%d\t", root->data);
	traverse(root->left);
	traverse(root->right);
}

BTREE delete_node(BTREE root, int x) {
	BTREE p, q;
	if(root==NULL) 
	return NULL;
	if(root->data==x) {
		if(root->left==root->right) {
			free(root);
			return NULL;
		}
			else {
				if(root->left==NULL) {
					p=root->right;
					free(root);
					return p;
				}
				else if (root->right==NULL) {
					p=root->left;
					free(root);
					return p;
				}
				else {
					p=q=root->right;
					while(p->left!=NULL)
					p=p->left;
					p->left=root->left;
					free(root);
					return q;
				}
			}
		}
		if(root->data<x) {
			root->right=delete_node(root->right, x);
		}
		else {
			root->left=delete_node(root->left, x);
		}
		return root;
}
int main () {
	BTREE root = NULL;
	root=insert(root,12);
	root=insert(root, 55);
	root=insert(root, 21);
	root=insert(root, 3);
	
	traverse(root);
	delete_node(root,21);
	printf("\n");
	
	traverse(root);
	
	return 0;
}
