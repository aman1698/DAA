#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n,i,j,temp,min;
	clock_t start,end;
	double total;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand();
	start=clock();
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	end=clock();
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken = %lf\n",total);
}
