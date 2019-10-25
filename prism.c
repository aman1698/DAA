#include<stdio.h>
#include<stdlib.h>
int ne=1,min_cost=0;
void main()
{
	int n,source,visited[20],cost[20][20],i,j,a,b,min;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("enter the cost matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("enter the source\n");
	scanf("%d",&source);
	visited[source]=1;
	printf("minimum spanning tree\n");
	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(visited[i]==0)
						continue;
					else
					{
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}
		if(visited[a]==0 || visited[b]==0)
		{
			printf("\n edge %d(%d----->%d) = %d\n",ne++,a,b,min);
			min_cost=min_cost+min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("total cost =%d\n",min_cost);
}
	

