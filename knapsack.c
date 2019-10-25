#include<stdio.h>
#include<stdlib.h>
int V[20][20],v[20],w[20],item[20];
int maxi(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}
int knapsack(int i,int j)
{
	int val;
	if(V[i][j]<0)
	{
		if(j<w[i])
			val=knapsack(i-1,j);
		else
			val=maxi(knapsack(i-1,j) , knapsack(i-1,j-w[i])+v[i]);
		V[i][j]=val;
	}
	return V[i][j];
}
void main()
{
	int n,c,j,z,i;
	printf("enter the no of items\n");
	scanf("%d",&n);
	printf("enter the capacity\n");
	scanf("%d",&c);
	printf("enter the weights\n");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("enter the value\n");
	for(i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(i==0 || j==0)
				V[i][j]=0;
			else
				V[i][j]=-1;
		}
	}
	z=knapsack(n,c);
	printf("maximum value = %d\n",z);
	j=c;
	for(i=n;i>0;i--)
	{
		if(V[i][j]!=V[i-1][j])
		{
			item[i]=1;
			j=j-w[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		if(item[i]==1)
			printf("%d",i);
	}
}

	
