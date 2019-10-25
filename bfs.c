#include<stdio.h>
#include<stdlib.h>
int count;
void bfs(int a[20][20],int n,int visited[20],int source)
{
	int queue[20],f,r,u,v;
	f=0;
	r=-1;
	queue[++r]=source;
	count++;
	visited[source]=count;
	while(f<=r)
	{
		u=queue[f++];
		for(v=1;v<=n;v++)
		{
			if(a[u][v]==1 && visited[v]==0)
			{
				queue[++r]=v;
				count++;
				visited[v]=count;
			}
		}
	}
}
void main()
{
	int n,a[20][20],visited[20],source,i,j,visitorder[20];
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("\nenter the source\n");
	scanf("%d",&source);
	bfs(a,n,visited,source);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
			bfs(a,n,visited,i);
	}
	for(i=1;i<=n;i++)
		visitorder[visited[i]]=i;
	for(i=1;i<=n;i++)
		printf("%c\t",visitorder[i] + 64);
}
	
	
