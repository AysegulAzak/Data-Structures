#include <stdio.h>
#include <stdlib.h>

struct n{
	int x;
	struct n * next;
	struct n * prev;
};
typedef struct n node;

void bastir(node * r){
	while( r != NULL){
		printf("%d\n", r -> x); // x yani data
		r = r -> next;
	}
}
node * ekleSirali(node * r, int x){
	if(r == NULL){ // linkist boþsa
		r =(node *)malloc(sizeof(node));
		r -> next = NULL;
		r -> prev = NULL;
		r -> x = x;
		return r;
 	}
 		if(r -> x > x) { // ilk elemandan küçük durumu
 		    //root deðiþiyor
 			node * temp =(node *)malloc(sizeof(node)); 
 			temp -> x = x;
 			temp -> next = r;
 			r = temp;
 			r -> prev = temp;
 			return temp;
		} 
 	node * iter = r;
 	while(iter -> next != NULL && iter -> next -> x < x){ // ortasýna ekleme
 		iter = iter -> next;
	}
	node * temp =(node *)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> prev = iter;
	if( temp -> next != NULL){
		temp -> next -> prev = temp;
	}
	temp -> x = x;
	return r;
}
node * sil(node * r, int x){
	node * temp;
	node * iter = r;
	if(r -> x == x){
		temp = r;
		r = r -> next;
		free(temp);
		return r;
	}
	while(iter -> next != NULL && iter -> next -> x != x) {
		iter = iter -> next;
	}
	if(iter -> next == NULL){
	      printf("sayi bulunamadi ");
	      return r;
    }
    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);
    if( iter -> next != NULL){
    	iter -> next -> prev = iter;
	}
    return r;
}
int main() {
	node * root;
    root = NULL;
    
    root = ekleSirali(root,400);
    root = ekleSirali(root,40);
    root = ekleSirali(root,4);
	root = ekleSirali(root,450);
    root = ekleSirali(root,50);
	bastir(root);
	
	root = sil(root, 50);
		bastir(root);
	root = sil(root, 999);
		bastir(root);
	root = sil(root, 4);
		bastir(root);
	root = sil(root, 450);
		bastir(root);
}
