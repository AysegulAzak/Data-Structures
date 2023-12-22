#include <stdio.h>
#include <stdlib.h>

int *dizi;
int size = 2;
int top = 0;
int i;
int pop(){
	if(dizi == NULL){
		printf("dizi boþ");
		return -1;
	}
	if(top <= size/4){
		int *dizi2 = (int *)malloc(sizeof(int) * size/2);
		for(i=0; i<top; i++){
			dizi2[i] = dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		size = size / 2;
	}
	return dizi[--top];
}
void push(int a){
	if(dizi == NULL){
		dizi = (int *)malloc(sizeof(int)*2);
	}
	if(top >= size) {
		int *dizi2 = (int *)malloc(sizeof(int)*size * 2);// int tipine çevir
		for(i=0; i<size; i++){
			dizi2[i] = dizi[i]; // dizideki elemanlarý kopyaladýk
		}
		free(dizi);
	    dizi = dizi2;
		size = size * 2;
	}
	dizi[top++] =a;
}
void bastir(){
	printf("size : %d ", size);
	for(i=0; i<top; i++){
		printf("%d ", dizi[i]);
	}
}
int main() {
	dizi = (int *)malloc(sizeof(int)*2); //dinamik kullaným //iki tane int koyulacak diziyi yap
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	bastir();
	
	printf("popped %d", pop());
	printf("popped %d", pop());
	printf("popped %d", pop());
	printf("popped %d", pop());
	printf("popped %d", pop());
	bastir();
	
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
    bastir();
}
