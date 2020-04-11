#include <iostream>
#include <math.h>
using namespace std;
const int M = 5;
const int N = 6;
int x[5]={0};
	int m[M][N]={0};
	int F[M][N] = { 0 };
int MaxProfit(int F[M][N],int f[M][N],int mm,int money)
{
    
	for (int i = 1; i <= mm; i++)
	{
		for (int j = 0; j <= money; j++)
		{
			F[i][j] = 0;
			m[i][j] = 0;
			for (int k = 0; k <= j; k++)
			{
				if (F[i][j] < f[i][k] + F[i - 1][j - k]){
					F[i][j] = f[i][k] + F[i - 1][j - k];
					m[i][j]=k;}
			}
		}
	}
	return F[mm][money];
}

void jie(int mm, int money,int x[5],int F[M][N])
{
  for(int i=mm;i>=1;i--)
  {
    x[i]=m[i][money];
    money=money-x[i];
    cout<<"第"<<i<<"个项目投资了"<<x[i]<<"元钱"<<endl;
  }
  
}
int main(int argc, char** argv)
{
	
	
	int f[M][N] = { 0,0,0,0,0,0,
				   0,11,12,13,14,15,
				   0,0,5,10,15,20,
				   0,2,10,30,32,40,
				   0,20,21,22,23,24 };
	int money;
	cin>>money;

	cout << MaxProfit(F, f, 4, money)<<endl;
	jie(4,money,x,F); 
	system("pause");
	return 0;
}


