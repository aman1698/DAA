#include<stdio.h>
#include<stdlib.h>
void warshall(int r[100][100],int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				r[i][j]=r[i][j] || (r[i][k] && r[k][j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",r[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int n,r[100][100],i,j;
	printf("enter the size of matrix\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&r[i][j]);
		}
	}
	warshall(r,n);
}

