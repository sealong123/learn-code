#include<iostream>
using namespace std;
typedef struct node{
	int data;
	int flag;
	node *left;
	node *right;
	node *fa;
	int number;
}node,*tree;
void create(tree &t){
	int a;
	cin>>a;
	if(a == 0){
		t = NULL;
		return;
	}
	else{
		node *p = new node;
		t = p;
		t->data = a;
		t->flag = 0;
		t->number = 0;
		create(t->left);
		if(t->left)t->left->fa = t;
		create(t->right);
		if(t->right)t->right->fa = t;	
	}
	return;
}
int find(tree t,tree &p){
	int max;
	if(t == NULL)return 0;
	else if(t->left == NULL & t->right == NULL){
		max = t->data;
		t->number = 1;
		t->flag = 1;
	}
	else{
		int l = find(t->left,p);
		int r = find(t->right,p);
		if(l != 0 && l*t->data > r){
			max = t->data * l;
			t->number = t->left->number + 1;
			t->flag = 1;
			p = t;
		}
		else if(l == 0 && t->data >= r){
			max = t->data;
			t->number = 1;
			p = t;
			t->flag = 1;
		}
		else if(l*t->data < r)max = r;
		else{
			if(t->left && p && t->left->number+1 <= p->number){
				max = t->data * l;
				t->number = t->left->number + 1;
				t->flag = 1;
				p = t;
			}
			else if(t->left && p && t->left->number+1 > p->number)max = r;
		}
	}
	return max;
}
void order(tree &t,int &flag1){
	if(t == NULL)return;
	if(flag1  == 1 ){
		if(t->flag == 1 && t->data == 1)order(t->left,flag1);
		else if(t->flag == 1 && t->data != 1){
			flag1 = 0;
			cout<<t->data<<' ';
			order(t->left,flag1);
		}
		else{
			node *p = t;
			while(p && p->flag == 0){
				p = p->right;
			}
			order(p,flag1);
		}
	}
	else{
		node *p = t;
		if(p->flag != 0){
			cout<<p->data<<' ';
			order(p->left,flag1);
		}
		else{
			while(p && p->flag == 0){
				p = p->right;
			}
			cout<<p->data<<' ';
		}
		order(p->left,flag1);
		}
}
int main(void){
	tree t;
	create(t);
	node *queue[1000];
	node *p = NULL;
	int Max = t->data * find(t->left,p);
	int flag1 = 1;
	cout<<Max<<endl;
	if(t->data == 1){
		p = t->left;
		order(p,flag1);
	}
	else{
		cout<<t->data<<' ';
		order(t->left,flag1);
	}
	return 0;
}
