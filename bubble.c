#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n,i,j,temp;
	clock_t start,end;
	double total;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand();
	start=clock();
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	end=clock();
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken = %lf\n",total);
}
