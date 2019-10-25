#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int H[100000];
void heap(int H[],int n)
{
	int i,j,k,v,heap=0;
	for(i=n/2;i>0;i--)
	{
		k=i;
		v=H[k];
		heap=0;
		while(!heap && (2*k<=n))
		{
			j=2*k;
			if(j<n)
			{
				if(H[j]<H[j+1])
					j=j+1;	
			}
			if(v>=H[j])
			{
				heap=1;
			}
			else
			{
				H[k]=H[j];
				k=j;
			}
		}
		H[k]=v;
	}
}
void main()
{
	int n,i,j=1,size,A[100000];
	clock_t start,end;
	double total;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		H[i]=rand();
	start=clock();
	heap(H,n);
	size=n;
	while(size>0)
	{
		int temp1=H[1];
		H[1]=H[size];
		H[size]=temp1;
		A[j++]=H[size];
		size=size-1;
		heap(H,size);
	}
	end=clock();
	total=(double)(end-start)/CLOCKS_PER_SEC;
	printf("time taken = %lf\n",total);
}
