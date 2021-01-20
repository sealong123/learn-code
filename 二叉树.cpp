#include<iostream>
using namespace std;
typedef struct Tnode{
    int data;
    Tnode *left,*right;
}tnode,*tree;
void Tcreate(tree &t,int &n){
    if(n > 150000)return;
    int a;
    tnode *p = (tnode*)malloc(sizeof(tnode));
    t = p;
    t->left = NULL;
    t->right = NULL;
    scanf("%d",&a);
    if(a == 0){t = NULL;return;}
    else{
        p->data = a;
        n++;
        Tcreate(t->left,n);
        Tcreate(t->right,n);
    }
    return;
}
void pre_order(tree t){
    if(t == NULL)return;
    else{
        cout<<t->data<<' ';
        pre_order(t->left);
        pre_order(t->right);
    }
}
void mid_order(tree t){
    if(t == NULL)return;
    mid_order(t->left);
    cout<<t->data<<' ';
    mid_order(t->right);
    return;
}
void bey_order(tree t){
    if(t == NULL)return;
    bey_order(t->left);
    bey_order(t->right);
    cout<<t->data<<' ';
    return;
}
void findfa(tree &t,tnode *&s,tnode *&q){
    if(t == NULL)return;
    findfa(t->left,s,q);
    if(t->left == s || t->right == s){
        q = t;
        return;
    }
    if(q != NULL)return;                  //这步一定要有，可以减少递归次数。
    findfa(t->right,s,q);
    return;
}
void find(tree &t,int &data,tnode *&s){             //经常结点指针忘加 * !!!
    if(t == NULL)return;
    find(t->left,data,s);
    if(t->data == data){
        s = t;
        return;
    }
    if(s != NULL)return;
    else{
        find(t->right,data,s);
    }
    return;
}
/*void Tfind(tree &t,int data,int &flag){
    if(t == NULL)return;
    else{
        if(t->data == data){
            if(t->dad == NULL){printf("0\n");flag = 0;}
            else{ printf("%d\n",t->dad->data);flag = 0;}
            return;
        }
        Tfind(t->left,data,flag);
        if(!flag)return;
        Tfind(t->right,data,flag);
    }
    return;
}
void Tdelete(tree &t,int &data,int &flag){
    if(t == NULL)return;
    else if(t->data == data){
        if(t->dad->left == t)t->dad->left = NULL;
        else t->dad->right = NULL;
        flag =0;
        //cout<<data<<endl;
        return;
    }
    if(!flag)return;
    Tdelete(t->left,data,flag);
    if(!flag)return;
    Tdelete(t->right,data,flag);
    return;
}*/  


int main(void){
    tree t = NULL;
    tnode *s = NULL,*q = NULL;
    int n = 0,flag = 1;
    Tcreate(t,n);
    //bey_order(t);
    int m,data;
    cin>>m;
    if(m<101){
        for(int i = 0;i < m;i++){
            /*cin>>data;
            Tdelete(t,data,flag);
            if(flag == 1)cout<<0<<endl;
            else{
                mid_order(t);
                cout<<endl;
            }
            flag = 1;*/
            cin>>data;
            find(t,data,s);
            if(s == NULL)cout<<0<<endl;
            else {
                findfa(t,s,q);
                if(q == NULL)cout<<0<<endl;
                else {
                    if(q->left == s)q->left = NULL;
                    else q->right = NULL;
                    mid_order(t);
                    cout<<endl;
                }
                s = NULL;
                q = NULL;
            }
        }
    }
    return 0;
}