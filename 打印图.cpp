#include<iostream>
using namespace std;
typedef struct edgenode{
	int index;
	int val;
	edgenode *next;
}edgenode;
typedef struct vnode{
	edgenode *head;
}vnode,vlist[20000];
void create(vlist list,int e){
	int i,num,ind,val1;
	edgenode *q = new edgenode;
	for(i = 0;i < e;i++){
		scanf("%d%d%d",&num,&ind,&val1);
		edgenode *p = new edgenode;
		q = list[num].head;
		p->index = ind;
		p->val = val1;
		while(q->next && p->index > q->next->index)q = q->next;
		p->next = q->next;
		q->next = p;
	}
}
void BFS(vlist list,int e,int n){
	int i;
	edgenode *p = new edgenode;
	for(i = 0;i < n && e;i++){
		p = list[i].head->next;
		if(p){
			printf("%d:",i);
			while(p){
				printf("(%d,%d,%d)",i,p->index,p->val);
				p = p->next;
				e--;
			}
			if(e)printf("\n");
		}
	}
}
int main(void){
	int n,e,i,visit[20000] = {0};
	scanf("%d%d",&n,&e);
	vlist list;
	for(i = 0;i < n;i++){
		list[i].head = new edgenode;
		list[i].head->next = NULL;                                   //изн╩╫А╣Ц 
	}
	create(list,e);
	BFS(list,e,n);
} 
