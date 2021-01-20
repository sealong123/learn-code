#include<iostream>
using namespace std;
typedef struct node{
    int data;
    node *next;
}node;
class queue{
    public:
    node* front;
    node* rear;
    queue(){
    	front = new node;
    	rear = new node;
        front = nullptr;
        rear = front;
    }
    void Insert(int &item);
    void Delete();
};
void queue::Insert(int &item){
    node *p = new node;
    p->data = item;
    p->next = nullptr;
    if(front == nullptr){
        rear = p;
        front = p;
        return;
    }
    rear->next = p;
    rear = p;
    return;
}
void queue::Delete(){
    if(front == nullptr){
        cout<<"invalid"<<endl;
        return;
    }
    node *p = new node;
    p = front;
    cout<<p->data<<endl;
    front = p->next;
    delete p;
    if(front == nullptr){
        rear = nullptr;              
    }                                      //这步不要忘！！！
    return;
}
int main(void){
    int n,number;
    int flag;
    cin>>n;
    queue s;
    if(n<20000||n == 20000){
    for(int i = 0;i<n;i++){
        cin>>flag;
        if(flag == 0){
			s.Delete();
            continue;
        }
        if(flag == 1){
            cin>>number;
            s.Insert(number);
            continue;
        }
    }
    }
    return 0;
}