#include<iostream>
#include<cstdlib> 
using namespace std;
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node,*tree;
tree create(){
	int a;
	scanf("%d",&a);
	node *p = (node*)malloc(sizeof(node));
	if(a == 0)return NULL;
	else{
		p->data = a;
		p->left = create();
		p->right = create();
	}
	return p;
}
tree fun(tree t){
	if(t == NULL)return NULL;
	else if(t->left == NULL&&t->right == NULL)return t;
	node *p = (node*)malloc(sizeof(node));
	node *q = (node*)malloc(sizeof(node));
	p = fun(t->left);
	q = fun(t->right);
	if(t->left != NULL){
		p->right = t->right;
		t->right = t->left;
		t->left = NULL; 
	}
	if(q == NULL)return p;
	else return q;
}
void print(tree t){
	if(t == NULL){
		cout<<0;
		return;
	}
	else{
		cout<<t->data;
		print(t->left);
		print(t->right);
	}
	return;
}
tree g(tree t){
	if(t == NULL){
		cout<<'@';
		return NULL;
	}
}
int main(void){
	tree t;
	t = create();
	tree q = NULL;
	tree p =fun(t);
	print(t);
}
