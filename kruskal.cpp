#include<cstdio>
#include<algorithm>
#define Max 100
int n;//顶点数 
struct edge {
	int from,to,value;
}e[Max];

bool cmp(edge a,edge b){
	return a.value<b.value;
}

int father[Max];

void init(int n){//初始化 
	int i;
	for(i=0;i<n;i++){
		father[i]=i;//定义每个节点的父节点是本身 
	}
}

int find(int root){
	int son,tmp;
	son=root;
	while(root!=father[root]){//寻找源头父节点 
		root=father[root];
	}
	while(son!=root){//压缩路径，直接将节点指向父节点 
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
	if(x!=y){//父节点不同的两个节点改成统一父节点 
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
	
	printf("输入顶点个数:");
	scanf("%d",&n); 
	init(n);
	int i,SUM;
	for(i=0;i<n*(n-1)/2;i++){
		printf("输入起始点，终止点，权值，以空格分开:");
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].value); 
	}
	SUM=kruskal();
	printf("%d",SUM);
	return 0;
} 







