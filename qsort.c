#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[],int low,int high)
{
	int i=low;
	int temp,temp1;
	int pivot=low;
	int j=high;
	while(i<j)
	{
		while(a[pivot]>=a[i] && i<high)
			i++;
		while(a[pivot]<=a[j] && j>low)
			j--;
		if(i<j)
		{
			temp1=a[i];
			a[i]=a[j];
			a[j]=temp1;
		}
	}
	
	temp=a[j];
	a[j]=a[pivot];
	a[pivot]=temp;
	return j;
}
void qsort1(int a[],int low,int high)
{
	if(low<high)
	{
		int s=partition(a,low,high);
		qsort1(a,low,s-1);
		qsort1(a,s+1,high);
	}
}
void main()
{
	int n,i,j;
	printf("enter the size of n\n");
	scanf("%d",&n);
	int a[n];
	clock_t start,end;
	double total;
	for(i=0;i<n;i++)
		a[i]=rand();
	start=clock();
	qsort1(a,0,n-1);
	end=clock();
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken = %lf\n",total);
	
}
