#include<stdio.h>

int graph[100][100]; 

void Prim(int n,int graph[][100],int v0){//nΪ�������graphΪͼ��v0ָ��ʼ�� 
	int value[n];//����n���Ȩֵ 
	int visited[n];//n���Ƿ����� 
	int v,sum,pos,min,i,j;//vָ��ղ������ĵ㣬sumΪ��С������Ȩֵ֮�ͣ�����Ϊ�������� 
	for(i=0;i<n;i++){//Ȩֵ�Ͳ�����С�������Ľ���ʼ�� 
		value[i]=graph[v0][i];
		visited[i]=0;//0��ʾδ������С��������1��ʾ�Ѳ�����С������ 
	}
	//��ʼ�����Ȳ�����С������ 
	v=v0;
	visited[v]=1;
	sum=0;
	for(i=0;i<n-1;i++){//��ʼ���Ѿ����룬��һ�ּ��� 
		min=100;
		for(j=0;j<n;j++){
			if(visited[j]==0&&value[j]<min){//ѡ������������ĵ㵽��������Ȩֵ�ı� 
				min=value[j];
				pos=j;
			}
		}
		visited[pos]=1;//������㲢���� 
		v=pos;//vʼ��ָ��ղ������ĵ�
		sum+=min;
		for(j=0;j<n;j++){//����������ĵ㵽��Ȩֵ 
			if(visited[j]==0&&value[j]>graph[v][j]){
				value[j]=graph[v][j];
			}
		} 
	}
	printf("%d\n",sum);
}

int main(){
	int n,vfirst,cost;
	printf("���������"); 
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j]=100;
		}
	}
	printf("��������ʼ�㣬��ֹ�㣬Ȩֵ��");
	for(k=0;k<n*(n-1)/2;k++){
		scanf("%d%d%d",&i,&j,&cost);
		graph[i][j]=cost;
	}
	printf("������ʼ�㣺");
	scanf("%d",&vfirst); 
	Prim(n,graph,vfirst);
} 



