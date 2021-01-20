#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
void insertsort(int *a,int max,int *move,int *compare){                //≤Â»Î≈≈–Ú 
	int i,j,k;
	*compare = 0;
	*move = 0;
	for(i = 1;i<max;i++){
		j = i-1;
		int t = a[i];
		while(a[j]>a[i]&&j>-1){
			*compare = *compare +1;
			j--;
		}
		*compare = *compare + 1;
		for(k = i-1;k>j;k--){
			a[k+1] = a[k]; 
			*move = *move + 1;
		}
		a[j+1] = t;
		if(j!=i-1)*move = *move + 1;
	}
}
void sort(int *a,int max,int *move,int *compare){                     //÷˜‘™≈≈–Ú 
	int i,j,k,t;
	*compare = 0;
	*move = 0;
	for(i = 0;i<max-1;i++){
		j = i;
		for(k = i+1;k<max;k++){
			if(a[k]<a[j])j = k;
			*compare = *compare + 1;
		}
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		*move = *move + 1;
	}
}
void popsort(int *a,int max,int *move,int *compare){       //√∞≈›≈≈–Ú 
	 int i,j,k,t;
	 *move = 0;
	 *compare = 0;
	 int flag = 1;
	 for(i = 0;i<max&&flag;i++){
	 	flag = 0;
	 	for(j = 0;j<max-1;j++){
	 		if(a[j]>a[j+1]){
	 			t = a[j];
	 			a[j] = a[j+1];
	 			a[j+1] = t;
	 			*move = *move + 1;
	 			flag = 1;
	 		}
	 		*compare = *compare + 1;
	 	}
	 }
}
int main (void){
	int i;
	int a[10],b[10],c[10];
	for(i = 0;i<10;i++)scanf("%d",&a[i]);
	for(i = 0;i<10;i++){
		b[i] = a[i];
		c[i] = a[i];
	}
	int move,compare;
	int *p,*q;
	p = &move;
	q = &compare;
	sort(a,10,p,q);
	printf("%d %d ",compare,move);
	popsort(b,10,p,q);
	printf("%d %d ",compare,move);
	insertsort(c,10,p,q);
	printf("%d %d",compare,move);
}
