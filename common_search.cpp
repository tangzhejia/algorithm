#include<stdio.h>
int main(void){
	int arr[]={1,5,9,14,16,23,25,25,29,36,36,44,45,46,46,53,57,59,62,64,67,71,74,77,82
			,86,89,91,92,97,100,109,110,113,115,120,128,131,134,134,136,136,139,141
			,144,150,152,156,158,163,166,166,170,172,172,175,178,182,184,184,189,190
			,192,199,206,212,213,214,215,215,215,219,219,219,222,224,228,233,234,235
			,235,235,235,236,238,240,246,246,250,254,255,256,258,262,266,271,278,280,285
			};
	int n,i,count=0;
	int len=sizeof(arr)/sizeof(arr[0]);
	printf("请输入要查找的数："); 
	scanf("%d",&n);
	for(i=0;i<=len;i++){
		if(i==len){
			printf("j=0");
			break;
		}
		else{
			if(n==arr[i]){
				printf("%d",i);
				break;
			}
			else{
				continue;
			}
		}
		
	}
} 
