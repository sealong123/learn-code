#include<iostream>
#define inf 2e9
using namespace std;
int apart(int *sort,int start,int end){
	int i = start,j = end+1,temp = sort[start];
	while(i < j){
		i++;j--;
		while(sort[i] <= temp)i++;
		while(sort[j] > temp)j--;
		if(i < j){
			int t = sort[i];
			sort[i] = sort[j];
			sort[j] = t;
		}
	}
	int p = sort[j];
	sort[j] = sort[start];
	sort[start] = p;
	return j;
}
void quicksort(int *sort,int left,int right){
	if(left < right){
		int j = apart(sort,left,right);
		quicksort(sort,left,j-1);
		quicksort(sort,j+1,right);
	}
	return;
}
int main(void){
	int sort[50001],n,i;
	scanf("%d",&n);
	for(i = 0;i < n;i++)scanf("%d",&sort[i]);
	sort[n] = inf;
	quicksort(sort,0,n);
	for(i = 0;i < n;i++)printf("%d ",sort[i]);
	return 0;
}
