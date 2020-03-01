#include<stdio.h>

int graph[100][100]; 

void Prim(int n,int graph[][100],int v0){//n为结点数，graph为图，v0指起始点 
	int value[n];//树到n点的权值 
	int visited[n];//n点是否并入树 
	int v,sum,pos,min,i,j;//v指向刚并入树的点，sum为最小生成树权值之和，其他为辅助变量 
	for(i=0;i<n;i++){//权值和并入最小生成树的结点初始化 
		value[i]=graph[v0][i];
		visited[i]=0;//0表示未并入最小生成树，1表示已并入最小生成树 
	}
	//起始点首先并入最小生成树 
	v=v0;
	visited[v]=1;
	sum=0;
	for(i=0;i<n-1;i++){//起始点已经并入，少一轮计算 
		min=100;
		for(j=0;j<n;j++){
			if(visited[j]==0&&value[j]<min){//选出生成树以外的点到生成树最权值的边 
				min=value[j];
				pos=j;
			}
		}
		visited[pos]=1;//将这个点并入树 
		v=pos;//v始终指向刚并入树的点
		sum+=min;
		for(j=0;j<n;j++){//更新树以外的点到树权值 
			if(visited[j]==0&&value[j]>graph[v][j]){
				value[j]=graph[v][j];
			}
		} 
	}
	printf("%d\n",sum);
}

int main(){
	int n,vfirst,cost;
	printf("顶点个数："); 
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j]=100;
		}
	}
	printf("请输入起始点，终止点，权值：");
	for(k=0;k<n*(n-1)/2;k++){
		scanf("%d%d%d",&i,&j,&cost);
		graph[i][j]=cost;
	}
	printf("设置起始点：");
	scanf("%d",&vfirst); 
	Prim(n,graph,vfirst);
} 



