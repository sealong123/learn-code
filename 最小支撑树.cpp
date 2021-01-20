#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define inf 1e9
using namespace std;
typedef struct NU{
	int from;
	int val;
}NU;
typedef struct V{
	int from;
	int num;
	int val;
}V;
void min_spanningtree(int matrix[][300],int n){
	int count = 0,sum = 0;
	NU *b = new NU[n];
	V *a = new V[n];
	int i;
	for(i = 0;i < n;i++){
		b[i].from = 0;
		b[i].val = matrix[0][i];
	}
	b[0].from = -1;
	while(count < n-1){
		int min = inf,temp = -1;
		for(i = 0;i < n;i++){
			if(b[i].from != -1 && b[i].val < min){
				temp = i;
				min = b[i].val;
			}
		}
		if(temp == -1){
			printf("There is no minimum spanning tree.\n");
			return;
		}
		else{
			a[count].from = b[temp].from;
			a[count].num = temp;
			a[count].val = b[temp].val;
			sum += b[temp].val;
			b[temp].from = -1;
			int j;
			for(j = 0;j < n;j++){
				if(b[j].from != -1 && matrix[temp][j] < b[j].val){
					b[j].val = matrix[temp][j];
					b[j].from = temp;			
				}
			}
			count++;
		}
	}
	printf("%d\n",sum);
}
int main(){
	int n,e;
	int matrix[300][300];
	while(cin>>n>>e){
		int i,j;
		for(i = 0;i < 300;i++){
			for(j = 0;j < 300;j++){
				if(i == j)matrix[i][j] = 0;
				else matrix[i][j] = inf;
			}
		}
		int x,y,val1;
		for(i = 0;i < e;i++){
			scanf("%d%d%d",&x,&y,&val1);
			matrix[x][y] = val1;
			matrix[y][x] = val1;
		}	
		min_spanningtree(matrix,n);
	}
	return 0;
}

