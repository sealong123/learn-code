#include<iostream>
#include<cstring>
using namespace std;
char code1[20000],code2[20000],store[20000],text[5001];
int flag = 1;
typedef struct node{
	char data;
	int val;
	int height;
	int is;
	node *left;
	node *right;
	node *father;
}node,*tree;
tree root;
void Height(tree t){
	if(t == NULL)return;
	Height(t->father);
	if(t->father == NULL)t->height = 0;
	else t->height = t->father->height + 1;
	return;
}
void print(tree t){
	if(!t)return;
	t->is = 1;
	print(t->father);
	if(t->left&&t->left->is == 1){
		cout<<0;
		t->left->is = 0;
	}
	else if(t->right&&t->right->is == 1){
		cout<<1;
		t->right->is = 0;
	}
	return;
}
void translete(tree t,char *code,int i,char *store,int k){
	if(t->left == NULL && t->right == NULL){
		store[k++] = t->data;
		translete(root,code,i,store,k);
		return;
	}
	if(code[i] == '\0'){
		store[k] = '#';
		if(t->father == NULL)return;
		else {
			flag = 0;
			return;
		}
	}
	if(!flag)return;
	else{
		if(t->left != NULL && code[i] == '0')translete(t->left,code,i+1,store,k);
		else if(t->right != NULL && code[i] == '1')translete(t->right,code,i+1,store,k);
		else{
			flag = 0;
			return;
		}
	}
	return;
}
int main(void){
	int k,sort[26],times[26] = {0},order[26] = {0},count = 1,j;
	node *Ham[27],*printorder[27];
	int ham = 0;
	cin>>text>>code1>>code2;
	int i,length = strlen(text);
	for(i = 0;i < length;i++){
		k = text[i] - 'a';
		times[k]++;
		if(order[k] == 0)order[k] = count++;
	}
	for(i = 0,k = 0;i < 26;i++)if(times[i] != 0)sort[k++] = i;
	for(i = 1;i < k;i++){
		j = i-1;
		while(j > -1 && times[sort[i]] < times[sort[j]])j--;
		while(j > -1 && times[sort[i]] == times[sort[j]] && order[sort[i]] < order[sort[j]])j--;
		int temp = sort[i],m;
		for(m = i;m > j+1;m--)sort[m] = sort[m-1];
		sort[j+1] = temp;
	}
	for(i = 0;i < k;i++){
		node *q = new node;
		int letter = sort[i];
		q->data = 'a' + letter;
		q->left = NULL;
		q->right = NULL;
		q->father = NULL;
		q->val = times[letter];
		q->height = 0;
		printorder[ham] = q;
		Ham[ham++] = q; 
	}
	node *last = new node;
	last->val = 5002;
	printorder[ham] = last;
	Ham[ham] = last;
	int start = 0;
	while(ham > 1){
		node *a = new node;
		a->val = Ham[start]->val + Ham[start+1]->val;
		a->left = Ham[start];
		a->right = Ham[start+1];
		Ham[start]->father = a;
		Ham[start+1]->father = a;
		++start;
		i = start+1;
		while(a->val >= Ham[i]->val){
			Ham[i-1] = Ham[i];
			i++;
		}
		Ham[i-1] = a;
		ham--;
		if(ham == 1)root = a;
	}
	int sum = 0;
	for(i = 0;printorder[i] != last;i++){
		Height(printorder[i]);
		sum += printorder[i]->height * printorder[i]->val;
	}
	if(sum%8 == 0)sum = sum/8;
	else sum = sum/8 + 1;
	cout<<length<<' '<<sum<<endl;
	for(i = 0;printorder[i] != last;i++){
		cout<<printorder[i]->data<<':';
		print(printorder[i]);
		cout<<endl;
	}
	translete(root,code1,0,store,0);
	if(flag){
		for(i = 0;store[i] != '#';i++)cout<<store[i];
		cout<<endl;
	}
	else cout<<"INVALID"<<endl;
	flag = 1;
	translete(root,code2,0,store,0);
	if(flag)
		for(i = 0;store[i] != '#';i++)cout<<store[i];
	else cout<<"INVALID";
	return 0;
}











