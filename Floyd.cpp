#include<stdio.h>

void Floyd(int e[][4]){
	int i,j,k;
	for(k=0;k<4;k++){
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(e[i][j]>e[i][k]+e[k][j]){
					e[i][j]=e[i][k]+e[k][j];
				}
			}
		}
	}
	printf("  1  2  3  4\n");
	for(i=0;i<4;i++){
		printf("%d ",i+1);
		for(j=0;j<4;j++){
			printf("%d  ",e[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	
	//Í¼µÄ³õÊ¼»¯
	int e[4][4]={{0,2,6,4},{100,0,3,100},{7,100,0,1},{5,100,12,0}};
	Floyd(e);
} 
