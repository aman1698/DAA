#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int L[n1];
	int R[n2];
	int i,j,k;
	for(i=0;i<n1;i++)
		L[i]=a[l+i];
	for(j=0;j<n2;j++)
		R[j]=a[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]>R[j])
			a[k++]=R[j++];
		else
			a[k++]=L[i++];
	}
	for( ;i<n1;i++)
		a[k++]=L[i];
	for( ;j<n2;j++)
		a[k++]=R[j];
}
void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void main()
{
	int n,i,j;
	clock_t start,end;
	double total;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand();
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken = %lf \n",total);
}

