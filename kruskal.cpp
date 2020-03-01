#include<cstdio>
#include<algorithm>
#define Max 100
int n;//������ 
struct edge {
	int from,to,value;
}e[Max];

bool cmp(edge a,edge b){
	return a.value<b.value;
}

int father[Max];

void init(int n){//��ʼ�� 
	int i;
	for(i=0;i<n;i++){
		father[i]=i;//����ÿ���ڵ�ĸ��ڵ��Ǳ��� 
	}
}

int find(int root){
	int son,tmp;
	son=root;
	while(root!=father[root]){//Ѱ��Դͷ���ڵ� 
		root=father[root];
	}
	while(son!=root){//ѹ��·����ֱ�ӽ��ڵ�ָ�򸸽ڵ� 
		tmp=father[son];
		father[son]=root;
		son=tmp;
	}
	return root;
}

void combine(int root1,int root2){
	int x,y;
	x=find(root1);
	y=find(root2);
	if(x!=y){//���ڵ㲻ͬ�������ڵ�ĳ�ͳһ���ڵ� 
		father[x]=y;
	}
}

int kruskal(){
	int j,sum=0;
	std::sort(e+1,e+1+n*(n-1)/2,cmp);
	for(j=0;j<n;j++){
		if(e[j].from==e[j].to){
			continue;
		}
		else{
			combine(e[j].from,e[j].to);
		}
		sum+=e[j].value;
	}
	return sum;
}

int main(){
	
	printf("���붥�����:");
	scanf("%d",&n); 
	init(n);
	int i,SUM;
	for(i=0;i<n*(n-1)/2;i++){
		printf("������ʼ�㣬��ֹ�㣬Ȩֵ���Կո�ֿ�:");
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].value); 
	}
	SUM=kruskal();
	printf("%d",SUM);
	return 0;
} 







