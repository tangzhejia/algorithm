#include<iostream>
using namespace std;
const int MAX=2147483647;
int const M=7;
void MATRIX_CHAIN_ORDER(int *p,int Length,int m[][M],int s[][M])
{
	int q,n=Length-1;
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int l=2;l<=n;l++) 	/* 矩阵链的长度 */
	{
		for(int i=1;i<=n-l+1;i++) 
		{
			int j=i+l-1;         /* 等价于 l=j-i+1 */
			m[i][j]=MAX;
			for(int k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void PRINT_OPTIMAL_PARENS(int s[][M],int i,int j)
{
	if(i == j) cout<<"A"<<i;
	else
	{
		cout<<"(";
		PRINT_OPTIMAL_PARENS(s,i,s[i][j]);
		PRINT_OPTIMAL_PARENS(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
    int p[M]={30,35,15,5,10,20,25};
    int num;
	cout<<"输入要计算矩阵链中前几个矩阵： "; 
	cin>>num;
	int m[M][M],s[M][M];
	MATRIX_CHAIN_ORDER(p,M,m,s);
	cout<<"当n="<<num<<"时最优解为: \n"<<m[1][num];
	cout<<"\n括号化方案为：\n"; 
	PRINT_OPTIMAL_PARENS(s,1,num);
	return 0;
}
