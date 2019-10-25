#include<stdio.h>
#include<stdlib.h>
int count;
void bfs(int a[20][20],int n,int visited[20],int source)
{
	int u,v;
	count++;
	visited[source]=count;
	for(v=1;v<=n;v++)
	{
		if(a[source][v]==1 && visited[v]==0)
		{
			bfs(a,n,visited,v);
			
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
	
	
