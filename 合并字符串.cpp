#include <iostream>
#include <stdlib.h> 
using namespace std;
typedef struct node{
    int data;
    node * next;
}node,*linklist ;
void create(node* head){
    int n,a;
    cin>>n;
    /*node *p = (node*)malloc(sizeof(node));
    p = head;
    node *q = (node*)malloc(sizeof(node));
    while(p->next != NULL){
    p = p->next;
	}*/
    node* p = head;
    for(int i = 0;i < n;i++){
        while(p->next != NULL){
            p = p->next;
        }
        node* q = (node*)malloc(sizeof(node));
        cin>>a;
        q->data = a;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    /*q->data = item;
    q->next = p->next;
    p->next = q;*/
    return ;
}
void f(node * &a,node  * &b){                         //这里一定要用引用！！
    node* p = (node*)malloc(sizeof(node));
    node* q = (node*)malloc(sizeof(node));
    node* t = (node*)malloc(sizeof(node));
    p = a->next;
    q = b->next;
    a->next = NULL;
    //b = a;
    while(p != NULL || q != NULL){
        if(p == NULL){
            t = q;
            q = q->next;
            t->next = a->next;
            a->next = t;
            continue;
        }
        else if(q == NULL){
            t = p;
            p = p->next;
            t->next = a->next;
            a->next = t;
            continue;
        }
        if(q->data > p->data){
            t = p;
            p = p->next;
            t->next = a->next;
            a->next = t;
            continue;
        }
        if(q->data < p->data){
            t = q;
            q = q->next;
            t->next = a->next;
            a->next = t;
            continue;
        }
        if(p->data == q->data){
            t = p;
            p = p->next;
            q = q->next;
            t->next = a->next;
            a->next = t;
        }
    }
    b = a;
}
void display(linklist head){
    node* p = head->next;
    while(p != NULL){
        cout<<p->data<<' ';
        p = p->next;
    }
    cout<<endl;
    return;
}
int main(void){
    node *a,*b;
    a = (node*)malloc(sizeof(node));
    a->next = NULL;
    b = (node*)malloc(sizeof(node));
    b->next = NULL;
    /*int n,item1,m,item2,i,k;
    cin>>n;
    for( i = 0;i < n;i++){
        cin>>item1; 
        create(a,item1);
    }
    cin>>m;
    for(k = 0;k < m;k++){
        cin>>item2; 
        create(b,item2);
    }*/
    create(a);
    create(b);
    f(a,b);
    //b = a;
    display(a);
    display(b);
    return 0;
}