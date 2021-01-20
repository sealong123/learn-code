#include<iostream>
#include<cstdbool>
#include<cstring>
using namespace std;
bool flag = true;                     //判断insert的状态。            
typedef struct node{
    char data;
    node *next;
    node *pre;
}node,*link;
int length(char*s){
    int i;
    for(i = 0;s[i] != '\0';i++);
    return i;
}
void link_add(link &head,link &tail,node *&p,char ch){      
    if(flag) {
        if(p == tail){                              //光标在最后
            node *t = new node;
            t->next = p->next;
            t->pre = p;
            t->data = ch;
            p->next = t;
            p = t;
            tail = t;
        }
        else {                                     //光标在中间或最前面的插入操作
            node *t = new node;
            t->next = p->next;
            t->pre = p;
            t->data = ch;
            p->next->pre = t;
            p->next = t;
            p = t;
        }
    }
    else {                                        //光标的替换操作
        if(p == tail){
            node *t = new node;
            t->data = ch;
            t->pre = p;
            t->next = p->next;
            p->next = t;
            p = t;
            tail = t;
        }
        else if(p->next != tail){
            p = p->next;
            node *q = new node;
            q = p->pre;
            p = q;
            q = q->next;
            p->next = q->next;
            q->next->pre = p;
            delete q;
            node *t = new node;
            t->data = ch;
            t->pre = p;
            t->next = p->next;
            p->next->pre = t;
            p->next = t;
            p = t;
        }
        else{
            node *t = new node;
            t = tail;
            tail = p;
            p->next = NULL;
            delete t;
            node *q = new node;
            q->data = ch;
            q->pre = p;
            q->next = NULL;
            //p->next->pre = q;
            p->next = q;
            p = q;
            tail =q;
        }
    }
    return;
}
void link_delete(link &head,link &tail,node *&p){
    node *q = new node;
    q = p->pre;
    if(p == head)return;                      //光标在最前面，删除无效
    if(p == tail){
        tail = q;                    //当光标为最后时，删除操作得改变尾指针。
        p = q;
        q = q->next;
        p->next = q->next;
        delete q;
    }
    else{                           //光标在中间的删除。
        p = q;
        q = q->next;
        p->next = q->next;
        q->next->pre = p;
        delete q;
    }
    //if(head->next == NULL)tail = head;
    return;
}
int main(void){
    int is = 1;                                //标志是否要进行链表插入操作。
    //string s;
    char s[50001];
    link head,tail;
    head = new node;
    head->next = NULL;
    head->pre = NULL;
    node *p = head,*q = head;                   //p为光标指的前一个字符
    tail = head;
    cin.getline(s,50001);
    //getline(cin,s);                      //不能用cin，cin不接受空格。
    //cout<<s<<endl;
    //int length = s.length();
    int lengthd = strlen(s);
    for(int i = 0;i<lengthd;i++){
        switch (s[i]){
            case '[':p = head;is = 0;break;
            case ']':p = tail;is = 0;break;
            case '{':if(p != head) p = p->pre;           //若光标在最前面，左移光标无效
            is = 0;
            break;
            case '}':if(p->next!=NULL)p = p->next;is = 0;break;     //若光标在最后面，右移无效
            case '-':flag = !flag;is = 0;break;
            case '=':link_delete(head,tail,p);is = 0;break;
            default:is = 1;
        }
        if(is){
            link_add(head,tail,p,s[i]);
        }
    }
    p = head->next;
    while(p!=NULL){                                             //输出
        cout<<p->data;
        p = p->next;
    }
    return 0;
}