#include<iostream>
#include<cstdio>
using namespace std;
int count=0;
void f(char B[8][7],int i,int j,int count,int X[7],int Z[6]){
	if(i==0 || j==0)
		return ;
	else{
		if(B[i][j]=='-'){
			Z[count]=X[i-1];
			count++;
			f(B,i-1,j-1,count,X,Z);
		}
		else if(B[i][j]=='x'){
			f(B,i-1,j,count,X,Z);
		}
		else if(B[i][j]=='y'){
			f(B,i,j-1,count,X,Z);
		}
	}
}

int main(){
	int X[7]={1,2,3,2,4,1,2};
	int Y[6]={2,4,3,1,2,1};
	int Z[6];
	char B[8][7];
	int C[7][6];
	int i,j; 
	
	for(int i=0;i<6;i++)
		Z[i]=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<7;j++)
			B[i][j]='0';		
	}
	for(int i=0;i<7;i++){
		for(int j=0;j<6;j++)
			C[i][j]=0;	
	}
	for(i=1;i<7;i++)
		for(j=1;j<6;j++){
			if(i>0&&j>0&&X[i-1]==Y[j-1]){
				C[i][j]=C[i-1][j-1]+1;
				//B[i][j]='-';				
			}
			else if(i>0&&j>0&&X[i-1]!=Y[j-1]){
				if(C[i][j-1]<C[i-1][j]){
					C[i][j]=C[i-1][j];
					//B[i][j]='x';
				} 
				else{
					C[i][j]=C[i][j-1];
					//B[i][j]='y';
				}
			}
		}	
	for(i=1;i<8;i++)
		for(j=1;j<7;j++){
			if(i>0&&j>0&&X[i-1]==Y[j-1]){
				//C[i][j]=C[i-1][j-1]+1;
				B[i][j]='-';				
			}
			else if(i>0&&j>0&&X[i-1]!=Y[j-1]){
				if(C[i][j-1]<C[i-1][j]){
					//C[i][j]=C[i-1][j];
					B[i][j]='x';
				} 
				else{
					//C[i][j]=C[i][j-1];
					B[i][j]='y';
				}
			}
		}


	for(int i=0;i<8;i++){
		for(int j=0;j<7;j++)
			cout<<B[i][j]<<" ";
		cout<<endl;		
	}
	cout<<endl;
	for(int i=0;i<7;i++){
		for(int j=0;j<6;j++)
			cout<<C[i][j]<<" ";
		cout<<endl;		
	}
	cout<<endl;
	f(B,7,6,count,X,Z);
	for(int i=5;i>=0;i--){
	
		cout<<Z[i]<<" ";
		
	}
} 

