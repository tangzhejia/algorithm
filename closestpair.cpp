#include<iostream>
#include<math.h>   
#include<algorithm>

using namespace std;
#define MAX 0x3f3f3f3f  //定义无穷大
#define M 99999
 
struct point {
  double x, y;
}p[M];
 
int a[M];// 保存排序的索引
 
int cmpx(const point& a, const point& b)  //排序升序
{  
  return a.x < b.x;
}
 
int cmpy(int &a, int &b)   //排序升序
{
  return p[a].y < p[b].y;
}
 
inline double min(double a, double b)   //返回两个值中较小的
{
	return a < b ? a : b;
}
inline double dist(const point& a, const point& b)
{
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double closeset(int low, int high)
{
	if (low == high)   
		return MAX;
	if (low + 1 == high)  //即n=2，返回两点之间的距离
		return dist(p[low], p[high]);
	int mid = (low + high)>>1;  //右移一位，相当于除以2，但右移的运算速度更快，若使用(low+high)/2求中间位置容易溢出
	double ans = min(closeset(low, mid), closeset(mid+1, high));  //递归求出两边最小距离
	int i, j, c = 0;
	for (i = low; i <= high; i++) //统计那些点位于两虚线内，并记录
	{
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			a[c++] = i;
	}
	sort(a, a + c, cmpy);
	for(i = 0; i < c; i++)//比较s1中虚线内的点和s2中虚线内的点的距离是否存在有小于两侧最小对的
	{
		int k = i+7 > c ? c : i+7;  
		for (j = i+1; j < k; j++)
		{
			if (p[a[j]].y - p[a[i]].y > ans)  //如果位于中位线两侧的点的距离大于anx则跳出第一个循环
				break;
			ans = min(dist(p[a[i]], p[a[j]]), ans);   //如果有两个点小于两侧的最近对，则选出最小的点
		}
	}
	return ans;
}
 
int main()
{
	int n;  //一共多少个点
	double dmin;
	
	cout<<"共有坐标点数为："<<endl;
	cin>> n;
	cout<<"点的坐标为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"p"<<i+1<<":";
		cin>>p[i].x>>p[i].y;
	}
	for(int i= 0 ;i<n-1;i++){
        for(int  j= 0 ;j<n-i-1;j++){
            if(p[j].x>p[j+1].x){
                int temp=p[j].x;
                p[j].x=p[j+1].x;
                p[j+1].x=temp;
                int pos=p[j].y;
                p[j].y=p[j+1].y;
                p[j+1].y=pos;
            }
            if(p[j].y>p[j+1].y){
                int temp=p[j].x;
                p[j].x=p[j+1].x;
                p[j+1].x=temp;
                int pos=p[j].y;
                p[j].y=p[j+1].y;
                p[j+1].y=pos;
            }
        }
    }

	dmin=closeset(0, n-1);
	cout<<"最近的距离是："<<dmin<<endl;
	return 0;
}
  
