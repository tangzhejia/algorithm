#include<stdio.h>

void dijkstra(int graph[][8],int vstart,int vfinish){
	int i,j,k,min;
	int dis[8];
	bool visited[8];//������ʼ�㵽�±�Ȩֵ���Ƿ�������С·�� 
	for(i=0;i<8;i++){
		dis[i]=graph[vstart][i];
	}
	visited[vstart]=1;
	for(i=0;i<8;i++){
		min=100;k=0;
		for(j=0;j<8;j++){
			if(!visited[j]&&dis[j]<min){
				min=dis[j];
				k=j;	
			}
				
		}
		visited[k]=1;
		for(j=0;j<8;j++){
			if(!visited[j]&&dis[j]>(dis[k]+graph[k][j])){
				dis[j]=dis[k]+graph[k][j];
			}
		}
	}
	printf("%d",dis[vfinish]);
}

int main(){
	int g[8][8]={{0,1,100,100,100,100,100,100},{100,0,100,2,100,100,100,100}
	,{2,100,0,100,100,100,100,100},{100,100,1,0,100,8,100,100}
	,{100,100,100,2,0,100,2,100},{100,100,100,100,2,0,100,100}
	,{100,100,100,100,100,3,0,3},{100,100,100,100,100,2,100,0}};
	int start,finish;
	printf("������ʼ�����ֹ�㣨a~h�ֱ���0~7��ʾ����"); 
	scanf("%d%d",&start,&finish); 
	dijkstra(g,start,finish);
}
 
