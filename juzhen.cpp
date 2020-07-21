#include <stdio.h>
const int MAX=100;	//静态变量，控制矩阵大小
int n;	//定义相乘矩阵的个数
int p[MAX+1],m[MAX][MAX],s[MAX][MAX];

void MatrixChain()
{
	int i,r,k,j,t;
	for(i=1;i<=n;i++)	//填主对角线d1
	 {
	 	m[i][i]=0; 
	 } 
	 for(r=2;r<=n;r++)	//填对角线dj(j=2~n)
	 {
	 	for(i=1;i<=n-r+1;i++)	//填次对角线的各个元素
		 {
		 	 j=i+r-1;	//计算次对角线上第i行元素的列标
			 m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];	//计算Ai的次数做为初始值
			 s[i][j]=i;		//保存分界点
			  for(k=i+1;k<j;k++)
			  {
			  	t=m[i][k]+m[r+1][j]+p[i-1]*p[j]*p[k];
			  	if(t<m[i][k])
			  	{
			  		m[i][j]=t;
			  		s[i][j]=k;
			  	}
			  } 
		 } 
	 } 
}

void tb(int i,int j,int s[MAX][MAX])
{//根据s[][]记录的各个子段的最优解，将其输出
	if(i==j)
		return;
	tb(i,s[i][j],s);
	tb(s[i][j]+1,j,s);
	printf("Multiply A%d,%dand A%d,%d\n",i,s[i][j],s[i][j]+1,j); 
} 

int main()
{
	printf("请输入n:");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",&p[i]);
	MatrixChain();
	tb(1,n,s);
	printf("输出的最优解为%d\n",m[1][n]);
	printf("\n\n\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
