#include<stdio.h>
#include<stdlib.h>
void Merge(int A[],int B[],int L,int R,int REnd){
	int LEnd,Num,bb;
	int i;
	LEnd=R-1;
	bb=L;
	Num=REnd-L+1;
	while(L<=LEnd&&R<=REnd){
		if(A[L]<=A[R]){
			B[bb++]=A[L++];
		}
		else{
			B[bb++]=A[R++];
		}
	}
	while(L<=LEnd){
		B[bb++]=A[L++];
	}
	while(R<=REnd){
		B[bb++]=A[R++];
	}
	for(i=0;i<Num;i++,REnd--){
		A[REnd]=B[REnd];
	}
} 

void Merge_main(int A[],int B[],int N,int len){
	int i,j;
	for(i=0;i<=N-2*len;i+=2*len){
		Merge(A,B,i,i+len,i+2*len-1);
	}
	if(i+len<N){
		Merge(A,B,i,i+len,N-1);
	}
	else{
		for(j=i;j<N;j++){
			B[j]=A[j];
		}
	}
}

int Merge_Sort(int A[],int N){
	int len;
	int *B;
	len=1;
	B=(int*)malloc(N*sizeof(int));
	if(B!=NULL){
		while(len<N){
			Merge_main(A,B,N,len);
			len*=2;
			Merge_main(B,A,N,len);
			len*=2;
		}
	}
}

int main(){
	int i;
	int arr[]={1,324,2,45,4,235,68,35,7,27,543,656,34,467,72,765,17,26
	,47,466,8934,54,989,86,445076,67,29,69,1882,6294,51,764};
	Merge_Sort(arr,32);
	for(i=0;i<32;i++){
		printf("%d ",arr[i]);
	}
}







