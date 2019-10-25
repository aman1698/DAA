#include<stdio.h>
#include<stdlib.h>
void dij(int n,int source,int cost[20][20],int d[20])
{
	int visited[20],w,count,min,u;
	for(w=1;w<=n;w++)
	{
		visited[w]=0;
		d[w]=cost[source][w];
	}
	d[source]=0;
	visited[source]=1;
	count=2;
	while(count<=n)
	{
		min=999;
		for(w=1;w<=n;w++)
		{
			if(d[w]<min && !visited[w])
			{
				min=d[w];
				u=w;
			}
		}
		count++;
		visited[u]=1;
		for(w=1;w<=n;w++)
		{
			if(d[u]+cost[u][w]<d[w] && !visited[w])
				d[w]=d[u]+cost[u][w];
		}
	}
}
void main()
{
	int n,source,cost[20][20],d[20],i,j;
	printf("enter the nodes\n");
	scanf("%d",&n);
	printf("enter the cost matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("enter the source\n");
	scanf("%d",&source);
	dij(n,source,cost,d);
	for(i=1;i<=n;i++)
	{
		if(i!=source)
			printf("%d----->%d=%d\n",source,i,d[i]);
	}
}
