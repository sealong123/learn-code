#include<stdio.h>
#include<stdlib.h>
/*struct tnode;
typedef struct tnode node;
typedef struct tnode *tree;
struct tnode{
	int data;
	node *left;
	node *right;
	node *fa;
};*/
 typedef struct tnode{
     int data;
     struct tnode *left;
     struct tnode *right;
     struct tnode *fa;
 }node,*tree;
 tree create(){
     int a;
     scanf("%d",&a);
     //struct tnode* p = (node*)malloc(sizeof(node));
     //node *p = (node*)malloc(sizeof(node));
     //tree p = (node*)malloc(sizeof(node));
     //node *p = (tree)malloc(sizeof(node));
     node *p = (struct tnode*)malloc(sizeof(struct tnode));
     if(a == 0)return NULL;
     else{
         p->data = a;
         p->fa = NULL;
         p->left = create();
         if(p->left!=NULL)p->left->fa = p;
         p->right = create(); 
         if(p->right!=NULL)p->right->fa = p;
     }
     return p; 
 }
 void order(tree t){
 	if(t == NULL)return;
 	else{
 		order(t->fa);
 		if(t->fa == NULL)printf("%d",t->data);
 		else printf(",%d",t->data);
 	}
 	return;
 }
 void find(tree t,int sum){
     if(t == NULL)return;
     sum -= t->data;
     if(sum == 0&&t->left == NULL&&t->right == NULL){
         order(t);
         printf("\n");
         return;
     }
     find(t->left,sum);
     find(t->right,sum);
     return;
 }
int main(void){
    tree t;
    t = create();
    int sum;
    scanf("%d",&sum);
    find(t,sum);
    return 0;
}
