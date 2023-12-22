#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int height;
	struct node *left;
	struct node *right;
};
typedef struct node AVLTREE;

AVLTREE *new_node(int data) {
	AVLTREE *p = (AVLTREE*)malloc(sizeof(struct node));
	p->data=data;
	p->left=p->right=NULL;
	p->height=0;
	return p;
}


int maxValue(int x, int y) {
	return x >= y ? x:y;
}

int height(AVLTREE *root){
	if(root==NULL)
		return -1;
	else{
		int lheight, rheight;
		rheight=height(root->right);
		lheight=height(root->left);
		if(rheight>lheight)
			return rheight+1;
		else
			return lheight+1;
	}
}
void inorder(AVLTREE* root) {
	if(root!=NULL) {
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}


AVLTREE *rightRotate(AVLTREE *z) {
	AVLTREE* temp = z -> left;
	z -> left = temp -> right;
	temp -> right = z;
	z->height = maxValue(height(z->left), height(z->right)) +1;
	temp -> height = maxValue(height(temp->left), height(temp->right))+1;
	return temp;
}
AVLTREE *leftRotate(AVLTREE *z) {
	AVLTREE *temp = z->right;
	z->right=temp->left;
	temp->left=z;
	z->height=maxValue(height(z->left), height(z->right))+1;
	temp->height=maxValue(height(temp->left), height(temp->right))+1;
	return temp;
}
AVLTREE *leftRightRotate(AVLTREE *z) {
	z->left=leftRotate(z->left);
	return rightRotate(z);
}
AVLTREE *rightLeftRotate(AVLTREE *z) {
	z->right=rightRotate(z->right);
	return leftRotate(z);
}

AVLTREE *insertToAVL(int x, AVLTREE *tree)
{
	if(tree != NULL)
	{
		if(x<tree ->data)
		   tree->left=insertToAVL(x, tree->left);
		else if(x>tree->data)
		   tree->right=insertToAVL(x, tree->right);
		else
		   return tree;
		tree -> height = maxValue(height(tree->left), height(tree->right)) + 1;
		if((height(tree->left) - height(tree -> right)) > 1 && x < tree -> left -> data)
		   return rightRotate(tree);
		if(height(tree->left)- height(tree->right) >1 && x > tree -> left -> data) 
		   return leftRightRotate(tree);
		if(height(tree->left)- height(tree->right) < -1 && x > tree -> right -> data)
		   return leftRotate(tree);
		if(height(tree->left) - height(tree->right) < -1 && x < tree -> right -> data)
		   return rightLeftRotate (tree);
	}
	else
		tree = new_node(x);
    return tree;		
}


int main(){
	AVLTREE *agac=NULL;
	int key, secim;
	printf("Veri giriniz :"); 
	scanf("%d", &key);
	while(key != -1){
		agac=insertToAVL(key,agac);
		scanf("%d", &key);
	}
	do{
		printf("\n 1-Insert \n 2-Height \n 3-Inorder \n 4-Exit \n Seciminiz: ");
		scanf("%d", &secim);
		switch(secim){
			case 1:
				printf("Veri giriniz: ");
				scanf("%d", &key);
				agac=insertToAVL(key,agac);
				printf("Veri Eklendi.");
				break;
			case 2:
				//printf("Height=%d",height(agac));
				printf("Height=%d", agac->height);
				break;
			case 3:
				inorder(agac);
				break;
			case 4:
				exit(1);
			default:+
				printf("Hatali secim!");
				break;
		}
	}
	while(1);
	
	return 0;
}












